#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenExperimentationTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenExperimentationTests::ExperimentationTestData AutoGenExperimentationTests::testData;

void AutoGenExperimentationTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenExperimentationTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenExperimentationTests::AddTests()
{
    // Generated tests 
    AddTest("TestExperimentationCreateExclusionGroup", &AutoGenExperimentationTests::TestExperimentationCreateExclusionGroup);

    AddTest("TestExperimentationCreateExperiment", &AutoGenExperimentationTests::TestExperimentationCreateExperiment);

    AddTest("TestExperimentationDeleteExclusionGroup", &AutoGenExperimentationTests::TestExperimentationDeleteExclusionGroup);

    AddTest("TestExperimentationDeleteExperiment", &AutoGenExperimentationTests::TestExperimentationDeleteExperiment);

    AddTest("TestExperimentationGetExclusionGroups", &AutoGenExperimentationTests::TestExperimentationGetExclusionGroups);

    AddTest("TestExperimentationGetExclusionGroupTraffic", &AutoGenExperimentationTests::TestExperimentationGetExclusionGroupTraffic);

    AddTest("TestExperimentationGetExperiments", &AutoGenExperimentationTests::TestExperimentationGetExperiments);

    AddTest("TestExperimentationGetLatestScorecard", &AutoGenExperimentationTests::TestExperimentationGetLatestScorecard);

    AddTest("TestExperimentationGetTreatmentAssignment", &AutoGenExperimentationTests::TestExperimentationGetTreatmentAssignment);

    AddTest("TestExperimentationStartExperiment", &AutoGenExperimentationTests::TestExperimentationStartExperiment);

    AddTest("TestExperimentationStopExperiment", &AutoGenExperimentationTests::TestExperimentationStopExperiment);

    AddTest("TestExperimentationUpdateExclusionGroup", &AutoGenExperimentationTests::TestExperimentationUpdateExclusionGroup);

    AddTest("TestExperimentationUpdateExperiment", &AutoGenExperimentationTests::TestExperimentationUpdateExperiment);
}

void AutoGenExperimentationTests::ClassSetUp()
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

void AutoGenExperimentationTests::ClassTearDown()
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

void AutoGenExperimentationTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region CreateExclusionGroup

void AutoGenExperimentationTests::TestExperimentationCreateExclusionGroup(TestContext& testContext)
{
    struct CreateExclusionGroupResultHolder : public CreateExclusionGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationCreateExclusionGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationCreateExclusionGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationCreateExclusionGroupResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationCreateExclusionGroupResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateExclusionGroupResultHolder>>(testContext);

    PFExperimentationCreateExclusionGroupRequestWrapper<> request;
    FillCreateExclusionGroupRequest(request);
    LogCreateExclusionGroupRequest(&request.Model(), "TestExperimentationCreateExclusionGroup");
    HRESULT hr = PFExperimentationCreateExclusionGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationCreateExclusionGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region CreateExperiment

void AutoGenExperimentationTests::TestExperimentationCreateExperiment(TestContext& testContext)
{
    struct CreateExperimentResultHolder : public CreateExperimentResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationCreateExperimentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationCreateExperimentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationCreateExperimentResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationCreateExperimentResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateExperimentResultHolder>>(testContext);

    PFExperimentationCreateExperimentRequestWrapper<> request;
    FillCreateExperimentRequest(request);
    LogCreateExperimentRequest(&request.Model(), "TestExperimentationCreateExperiment");
    HRESULT hr = PFExperimentationCreateExperimentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationCreateExperimentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteExclusionGroup

void AutoGenExperimentationTests::TestExperimentationDeleteExclusionGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationDeleteExclusionGroupRequestWrapper<> request;
    FillDeleteExclusionGroupRequest(request);
    LogDeleteExclusionGroupRequest(&request.Model(), "TestExperimentationDeleteExclusionGroup");
    HRESULT hr = PFExperimentationDeleteExclusionGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationDeleteExclusionGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteExperiment

void AutoGenExperimentationTests::TestExperimentationDeleteExperiment(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationDeleteExperimentRequestWrapper<> request;
    FillDeleteExperimentRequest(request);
    LogDeleteExperimentRequest(&request.Model(), "TestExperimentationDeleteExperiment");
    HRESULT hr = PFExperimentationDeleteExperimentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationDeleteExperimentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetExclusionGroups

void AutoGenExperimentationTests::TestExperimentationGetExclusionGroups(TestContext& testContext)
{
    struct GetExclusionGroupsResultHolder : public GetExclusionGroupsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExclusionGroupsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExclusionGroupsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationGetExclusionGroupsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationGetExclusionGroupsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetExclusionGroupsResultHolder>>(testContext);

    PFExperimentationGetExclusionGroupsRequestWrapper<> request;
    FillGetExclusionGroupsRequest(request);
    LogGetExclusionGroupsRequest(&request.Model(), "TestExperimentationGetExclusionGroups");
    HRESULT hr = PFExperimentationGetExclusionGroupsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationGetExclusionGroupsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetExclusionGroupTraffic

void AutoGenExperimentationTests::TestExperimentationGetExclusionGroupTraffic(TestContext& testContext)
{
    struct GetExclusionGroupTrafficResultHolder : public GetExclusionGroupTrafficResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExclusionGroupTrafficGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExclusionGroupTrafficGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationGetExclusionGroupTrafficResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationGetExclusionGroupTrafficResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetExclusionGroupTrafficResultHolder>>(testContext);

    PFExperimentationGetExclusionGroupTrafficRequestWrapper<> request;
    FillGetExclusionGroupTrafficRequest(request);
    LogGetExclusionGroupTrafficRequest(&request.Model(), "TestExperimentationGetExclusionGroupTraffic");
    HRESULT hr = PFExperimentationGetExclusionGroupTrafficAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationGetExclusionGroupTrafficAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetExperiments

void AutoGenExperimentationTests::TestExperimentationGetExperiments(TestContext& testContext)
{
    struct GetExperimentsResultHolder : public GetExperimentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExperimentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationGetExperimentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationGetExperimentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationGetExperimentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetExperimentsResultHolder>>(testContext);

    PFExperimentationGetExperimentsRequestWrapper<> request;
    FillGetExperimentsRequest(request);
    LogGetExperimentsRequest(&request.Model(), "TestExperimentationGetExperiments");
    HRESULT hr = PFExperimentationGetExperimentsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationGetExperimentsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetLatestScorecard

void AutoGenExperimentationTests::TestExperimentationGetLatestScorecard(TestContext& testContext)
{
    struct GetLatestScorecardResultHolder : public GetLatestScorecardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationGetLatestScorecardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationGetLatestScorecardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationGetLatestScorecardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationGetLatestScorecardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetLatestScorecardResultHolder>>(testContext);

    PFExperimentationGetLatestScorecardRequestWrapper<> request;
    FillGetLatestScorecardRequest(request);
    LogGetLatestScorecardRequest(&request.Model(), "TestExperimentationGetLatestScorecard");
    HRESULT hr = PFExperimentationGetLatestScorecardAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationGetLatestScorecardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetTreatmentAssignment

void AutoGenExperimentationTests::TestExperimentationGetTreatmentAssignment(TestContext& testContext)
{
    struct GetTreatmentAssignmentResultHolder : public GetTreatmentAssignmentResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFExperimentationGetTreatmentAssignmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFExperimentationGetTreatmentAssignmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFExperimentationGetTreatmentAssignmentResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFExperimentationGetTreatmentAssignmentResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetTreatmentAssignmentResultHolder>>(testContext);

    PFExperimentationGetTreatmentAssignmentRequestWrapper<> request;
    FillGetTreatmentAssignmentRequest(request);
    LogGetTreatmentAssignmentRequest(&request.Model(), "TestExperimentationGetTreatmentAssignment");
    HRESULT hr = PFExperimentationGetTreatmentAssignmentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationGetTreatmentAssignmentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region StartExperiment

void AutoGenExperimentationTests::TestExperimentationStartExperiment(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationStartExperimentRequestWrapper<> request;
    FillStartExperimentRequest(request);
    LogStartExperimentRequest(&request.Model(), "TestExperimentationStartExperiment");
    HRESULT hr = PFExperimentationStartExperimentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationStartExperimentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region StopExperiment

void AutoGenExperimentationTests::TestExperimentationStopExperiment(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationStopExperimentRequestWrapper<> request;
    FillStopExperimentRequest(request);
    LogStopExperimentRequest(&request.Model(), "TestExperimentationStopExperiment");
    HRESULT hr = PFExperimentationStopExperimentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationStopExperimentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateExclusionGroup

void AutoGenExperimentationTests::TestExperimentationUpdateExclusionGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationUpdateExclusionGroupRequestWrapper<> request;
    FillUpdateExclusionGroupRequest(request);
    LogUpdateExclusionGroupRequest(&request.Model(), "TestExperimentationUpdateExclusionGroup");
    HRESULT hr = PFExperimentationUpdateExclusionGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationUpdateExclusionGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateExperiment

void AutoGenExperimentationTests::TestExperimentationUpdateExperiment(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFExperimentationUpdateExperimentRequestWrapper<> request;
    FillUpdateExperimentRequest(request);
    LogUpdateExperimentRequest(&request.Model(), "TestExperimentationUpdateExperiment");
    HRESULT hr = PFExperimentationUpdateExperimentAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFExperimentationExperimentationUpdateExperimentAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
