#include "stdafx.h"
#include "GlobalState.h"
#include "AsyncProvider.h"
#include "QoS/QoS.h"
#include <httpClient/httpClient.h>

using namespace PlayFab;

namespace PlayFab
{

GlobalState::GlobalState(String&& titleId, _In_opt_z_ const char* secretKey, _In_opt_ XTaskQueueHandle backgroundQueue) :
    m_titleId{ std::move(titleId) },
    m_httpClient{ MakeShared<PlayFab::HttpClient>(m_titleId) },
    m_secretKey{ secretKey ? MakeShared<String>(secretKey) : nullptr },
    m_qosAPI{ MakeShared<QoS::QoSAPI>() },
    m_backgroundQueue{ backgroundQueue }
{
}

String const& GlobalState::TitleId() const
{
    return m_titleId;
}

SharedPtr<HttpClient const> GlobalState::HttpClient() const
{
    return m_httpClient;
}

SharedPtr<String const> GlobalState::SecretKey() const
{
    return m_secretKey;
}

SharedPtr<QoS::QoSAPI const> GlobalState::QoSAPI() const
{
    return m_qosAPI;
}

} // namespace PlayFab

PFGlobalState::PFGlobalState(_In_z_ const char* titleId, _In_opt_z_ const char* secretKey, _In_opt_ XTaskQueueHandle backgroundQueue) :
    state{ MakeShared<GlobalState>(titleId, secretKey, backgroundQueue) }
{
}

HRESULT PFGlobalState::Create(
    _In_z_ const char* titleId,
    _In_opt_z_ const char* secretKey,
    _In_opt_ XTaskQueueHandle backgroundQueue,
    _Outptr_ PFStateHandle* stateHandle
)
{
    RETURN_HR_INVALIDARG_IF_NULL(titleId);
    RETURN_IF_FAILED(HCInitialize(nullptr));

    Allocator<PFGlobalState> a{};
    *stateHandle = UniquePtr<PFGlobalState>(new (a.allocate(1)) PFGlobalState(titleId, secretKey, backgroundQueue)).release();
    return S_OK;
}

HRESULT PFGlobalState::CleanupAsync(XAsyncBlock* async)
{
    struct CleanupProvider : public Provider
    {
        CleanupProvider(XAsyncBlock* async, PFStateHandle handle) :
            Provider{ async },
            stateHandle{ handle }
        {
        }

        HRESULT Begin(TaskQueue&& queue) override
        {
            if (stateHandle->state.use_count() > 1)
            {
                // Need to decide if it is client's responsibility to wait for any pending API calls to complete before
                // calling cleanup or if we should wait here
                return E_FAIL;
            }
            else
            {
                // stateHandle->state is the only remaining reference. GlobalState will be destroyed on this thread before
                // control returns to client
                UniquePtr<PFGlobalState> reclaim{ stateHandle };

                // Cleanup libHttpClient
                hcCleanupQueue = queue.DeriveWorkerQueue();
                hcCleanupAsync.queue = hcCleanupQueue.GetHandle();
                hcCleanupAsync.callback = HCCleanupComplete;
                hcCleanupAsync.context = this;

                RETURN_IF_FAILED(HCCleanupAsync(&hcCleanupAsync));

                return E_PENDING;
            }
        }

        static void CALLBACK HCCleanupComplete(XAsyncBlock* async)
        {
            CleanupProvider* self = static_cast<CleanupProvider*>(async->context);
            assert(self);

            HRESULT hr = XAsyncGetStatus(async, false);
            assert(hr != E_PENDING);

            if (hr == E_HC_INTERNAL_STILLINUSE)
            {
                // If something else is still referencing libHttpClient, we do not care
                self->Complete(0);
                return;
            }
            else if (FAILED(hr))
            {
                // Pass along HCCleanup error. Note that state is still destroyed
                self->Fail(hr);
                return;
            }

            self->Complete(0);
        }

        XAsyncBlock hcCleanupAsync{};
        TaskQueue hcCleanupQueue;
        PFStateHandle stateHandle;
    };

    return Provider::Run(UniquePtr<Provider>{ MakeUnique<CleanupProvider>(async, this).release() });
}
