#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCloudScriptTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenCloudScriptTests::CloudScriptTestData AutoGenCloudScriptTests::testData;

void AutoGenCloudScriptTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenCloudScriptTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenCloudScriptTests::AddTests()
{
    // Generated tests 
    AddTest("TestCloudScriptAdminGetCloudScriptRevision", &AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptRevision);

    AddTest("TestCloudScriptAdminGetCloudScriptVersions", &AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptVersions);

    AddTest("TestCloudScriptAdminSetPublishedRevision", &AutoGenCloudScriptTests::TestCloudScriptAdminSetPublishedRevision);

    AddTest("TestCloudScriptAdminUpdateCloudScript", &AutoGenCloudScriptTests::TestCloudScriptAdminUpdateCloudScript);

    AddTest("TestCloudScriptClientExecuteCloudScript", &AutoGenCloudScriptTests::TestCloudScriptClientExecuteCloudScript);

    AddTest("TestCloudScriptServerExecuteCloudScript", &AutoGenCloudScriptTests::TestCloudScriptServerExecuteCloudScript);

    AddTest("TestCloudScriptExecuteEntityCloudScript", &AutoGenCloudScriptTests::TestCloudScriptExecuteEntityCloudScript);

    AddTest("TestCloudScriptExecuteFunction", &AutoGenCloudScriptTests::TestCloudScriptExecuteFunction);

    AddTest("TestCloudScriptGetFunction", &AutoGenCloudScriptTests::TestCloudScriptGetFunction);

    AddTest("TestCloudScriptListFunctions", &AutoGenCloudScriptTests::TestCloudScriptListFunctions);

    AddTest("TestCloudScriptListHttpFunctions", &AutoGenCloudScriptTests::TestCloudScriptListHttpFunctions);

    AddTest("TestCloudScriptListQueuedFunctions", &AutoGenCloudScriptTests::TestCloudScriptListQueuedFunctions);

    AddTest("TestCloudScriptPostFunctionResultForEntityTriggeredAction", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForEntityTriggeredAction);

    AddTest("TestCloudScriptPostFunctionResultForFunctionExecution", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForFunctionExecution);

    AddTest("TestCloudScriptPostFunctionResultForPlayerTriggeredAction", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForPlayerTriggeredAction);

    AddTest("TestCloudScriptPostFunctionResultForScheduledTask", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForScheduledTask);

    AddTest("TestCloudScriptRegisterHttpFunction", &AutoGenCloudScriptTests::TestCloudScriptRegisterHttpFunction);

    AddTest("TestCloudScriptRegisterQueuedFunction", &AutoGenCloudScriptTests::TestCloudScriptRegisterQueuedFunction);

    AddTest("TestCloudScriptUnregisterFunction", &AutoGenCloudScriptTests::TestCloudScriptUnregisterFunction);
}

void AutoGenCloudScriptTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenCloudScriptTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenCloudScriptTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminGetCloudScriptRevision

void AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptRevision(TestContext& testContext)
{
    struct AdminGetCloudScriptRevisionResultHolder : public GetCloudScriptRevisionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptRevisionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptRevisionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptGetCloudScriptRevisionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptGetCloudScriptRevisionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCloudScriptRevisionResultHolder>>(testContext);

    PFCloudScriptGetCloudScriptRevisionRequestWrapper<> request;
    FillGetCloudScriptRevisionRequest(request);
    LogGetCloudScriptRevisionRequest(&request.Model(), "TestCloudScriptAdminGetCloudScriptRevision");
    HRESULT hr = PFCloudScriptAdminGetCloudScriptRevisionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminGetCloudScriptRevisionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetCloudScriptVersions

void AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptVersions(TestContext& testContext)
{
    struct AdminGetCloudScriptVersionsResultHolder : public GetCloudScriptVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptGetCloudScriptVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptGetCloudScriptVersionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCloudScriptVersionsResultHolder>>(testContext);

    HRESULT hr = PFCloudScriptAdminGetCloudScriptVersionsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminGetCloudScriptVersionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetPublishedRevision

void AutoGenCloudScriptTests::TestCloudScriptAdminSetPublishedRevision(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptSetPublishedRevisionRequestWrapper<> request;
    FillSetPublishedRevisionRequest(request);
    LogSetPublishedRevisionRequest(&request.Model(), "TestCloudScriptAdminSetPublishedRevision");
    HRESULT hr = PFCloudScriptAdminSetPublishedRevisionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminSetPublishedRevisionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateCloudScript

void AutoGenCloudScriptTests::TestCloudScriptAdminUpdateCloudScript(TestContext& testContext)
{
    struct AdminUpdateCloudScriptResultHolder : public UpdateCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminUpdateCloudScriptGetResult(async, &result)));
            LogPFCloudScriptUpdateCloudScriptResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptUpdateCloudScriptResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateCloudScriptResultHolder>>(testContext);

    PFCloudScriptUpdateCloudScriptRequestWrapper<> request;
    FillUpdateCloudScriptRequest(request);
    LogUpdateCloudScriptRequest(&request.Model(), "TestCloudScriptAdminUpdateCloudScript");
    HRESULT hr = PFCloudScriptAdminUpdateCloudScriptAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminUpdateCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientExecuteCloudScript

void AutoGenCloudScriptTests::TestCloudScriptClientExecuteCloudScript(TestContext& testContext)
{
    struct ClientExecuteCloudScriptResultHolder : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptClientExecuteCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptClientExecuteCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExecuteCloudScriptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientExecuteCloudScriptResultHolder>>(testContext);

    PFCloudScriptExecuteCloudScriptRequestWrapper<> request;
    FillExecuteCloudScriptRequest(request);
    LogExecuteCloudScriptRequest(&request.Model(), "TestCloudScriptClientExecuteCloudScript");
    HRESULT hr = PFCloudScriptClientExecuteCloudScriptAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptClientExecuteCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerExecuteCloudScript

void AutoGenCloudScriptTests::TestCloudScriptServerExecuteCloudScript(TestContext& testContext)
{
    struct ServerExecuteCloudScriptResultHolder : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptServerExecuteCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptServerExecuteCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExecuteCloudScriptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerExecuteCloudScriptResultHolder>>(testContext);

    PFCloudScriptExecuteCloudScriptServerRequestWrapper<> request;
    FillExecuteCloudScriptServerRequest(request);
    LogExecuteCloudScriptServerRequest(&request.Model(), "TestCloudScriptServerExecuteCloudScript");
    HRESULT hr = PFCloudScriptServerExecuteCloudScriptAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptServerExecuteCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ExecuteEntityCloudScript

void AutoGenCloudScriptTests::TestCloudScriptExecuteEntityCloudScript(TestContext& testContext)
{
    struct ExecuteEntityCloudScriptResultHolder : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteEntityCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteEntityCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExecuteCloudScriptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ExecuteEntityCloudScriptResultHolder>>(testContext);

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper<> request;
    FillExecuteEntityCloudScriptRequest(request);
    LogExecuteEntityCloudScriptRequest(&request.Model(), "TestCloudScriptExecuteEntityCloudScript");
    HRESULT hr = PFCloudScriptExecuteEntityCloudScriptAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptExecuteEntityCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ExecuteFunction

void AutoGenCloudScriptTests::TestCloudScriptExecuteFunction(TestContext& testContext)
{
    struct ExecuteFunctionResultHolder : public ExecuteFunctionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteFunctionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteFunctionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptExecuteFunctionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptExecuteFunctionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ExecuteFunctionResultHolder>>(testContext);

    PFCloudScriptExecuteFunctionRequestWrapper<> request;
    FillExecuteFunctionRequest(request);
    LogExecuteFunctionRequest(&request.Model(), "TestCloudScriptExecuteFunction");
    HRESULT hr = PFCloudScriptExecuteFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptExecuteFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetFunction

void AutoGenCloudScriptTests::TestCloudScriptGetFunction(TestContext& testContext)
{
    struct GetFunctionResultHolder : public GetFunctionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptGetFunctionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptGetFunctionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptGetFunctionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptGetFunctionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetFunctionResultHolder>>(testContext);

    PFCloudScriptGetFunctionRequestWrapper<> request;
    FillGetFunctionRequest(request);
    LogGetFunctionRequest(&request.Model(), "TestCloudScriptGetFunction");
    HRESULT hr = PFCloudScriptGetFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptGetFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListFunctions

void AutoGenCloudScriptTests::TestCloudScriptListFunctions(TestContext& testContext)
{
    struct ListFunctionsResultHolder : public ListFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptListFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptListFunctionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListFunctionsResultHolder>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListFunctions");
    HRESULT hr = PFCloudScriptListFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListFunctionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListHttpFunctions

void AutoGenCloudScriptTests::TestCloudScriptListHttpFunctions(TestContext& testContext)
{
    struct ListHttpFunctionsResultHolder : public ListHttpFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListHttpFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListHttpFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptListHttpFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptListHttpFunctionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListHttpFunctionsResultHolder>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListHttpFunctions");
    HRESULT hr = PFCloudScriptListHttpFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListHttpFunctionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListQueuedFunctions

void AutoGenCloudScriptTests::TestCloudScriptListQueuedFunctions(TestContext& testContext)
{
    struct ListQueuedFunctionsResultHolder : public ListQueuedFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListQueuedFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListQueuedFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCloudScriptListQueuedFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCloudScriptListQueuedFunctionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListQueuedFunctionsResultHolder>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListQueuedFunctions");
    HRESULT hr = PFCloudScriptListQueuedFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListQueuedFunctionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PostFunctionResultForEntityTriggeredAction

void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForEntityTriggeredAction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<> request;
    FillPostFunctionResultForEntityTriggeredActionRequest(request);
    LogPostFunctionResultForEntityTriggeredActionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForEntityTriggeredAction");
    HRESULT hr = PFCloudScriptPostFunctionResultForEntityTriggeredActionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForEntityTriggeredActionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PostFunctionResultForFunctionExecution

void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForFunctionExecution(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<> request;
    FillPostFunctionResultForFunctionExecutionRequest(request);
    LogPostFunctionResultForFunctionExecutionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForFunctionExecution");
    HRESULT hr = PFCloudScriptPostFunctionResultForFunctionExecutionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForFunctionExecutionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PostFunctionResultForPlayerTriggeredAction

void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForPlayerTriggeredAction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<> request;
    FillPostFunctionResultForPlayerTriggeredActionRequest(request);
    LogPostFunctionResultForPlayerTriggeredActionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForPlayerTriggeredAction");
    HRESULT hr = PFCloudScriptPostFunctionResultForPlayerTriggeredActionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForPlayerTriggeredActionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PostFunctionResultForScheduledTask

void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForScheduledTask(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<> request;
    FillPostFunctionResultForScheduledTaskRequest(request);
    LogPostFunctionResultForScheduledTaskRequest(&request.Model(), "TestCloudScriptPostFunctionResultForScheduledTask");
    HRESULT hr = PFCloudScriptPostFunctionResultForScheduledTaskAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForScheduledTaskAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RegisterHttpFunction

void AutoGenCloudScriptTests::TestCloudScriptRegisterHttpFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptRegisterHttpFunctionRequestWrapper<> request;
    FillRegisterHttpFunctionRequest(request);
    LogRegisterHttpFunctionRequest(&request.Model(), "TestCloudScriptRegisterHttpFunction");
    HRESULT hr = PFCloudScriptRegisterHttpFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptRegisterHttpFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RegisterQueuedFunction

void AutoGenCloudScriptTests::TestCloudScriptRegisterQueuedFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptRegisterQueuedFunctionRequestWrapper<> request;
    FillRegisterQueuedFunctionRequest(request);
    LogRegisterQueuedFunctionRequest(&request.Model(), "TestCloudScriptRegisterQueuedFunction");
    HRESULT hr = PFCloudScriptRegisterQueuedFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptRegisterQueuedFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UnregisterFunction

void AutoGenCloudScriptTests::TestCloudScriptUnregisterFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptUnregisterFunctionRequestWrapper<> request;
    FillUnregisterFunctionRequest(request);
    LogUnregisterFunctionRequest(&request.Model(), "TestCloudScriptUnregisterFunction");
    HRESULT hr = PFCloudScriptUnregisterFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptUnregisterFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
