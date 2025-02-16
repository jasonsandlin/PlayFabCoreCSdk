#pragma once

#include <playfab/cpp/PFSharedDataModelWrappers.h>
#include "BaseModel.h"

namespace PlayFab
{

// Shared Classes
class ItemInstance : public Wrappers::PFItemInstanceWrapper<Allocator>, public OutputModel<PFItemInstance>
{
public:
    using ModelWrapperType = typename Wrappers::PFItemInstanceWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFItemInstance const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFItemInstance& model);
    static HRESULT Copy(const PFItemInstance& input, PFItemInstance& output, ModelBuffer& buffer);
};

class ScriptExecutionError : public Wrappers::PFScriptExecutionErrorWrapper<Allocator>, public OutputModel<PFScriptExecutionError>
{
public:
    using ModelWrapperType = typename Wrappers::PFScriptExecutionErrorWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScriptExecutionError const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScriptExecutionError& model);
    static HRESULT Copy(const PFScriptExecutionError& input, PFScriptExecutionError& output, ModelBuffer& buffer);
};

class LogStatement : public Wrappers::PFLogStatementWrapper<Allocator>, public OutputModel<PFLogStatement>
{
public:
    using ModelWrapperType = typename Wrappers::PFLogStatementWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLogStatement const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLogStatement& model);
    static HRESULT Copy(const PFLogStatement& input, PFLogStatement& output, ModelBuffer& buffer);
};

class ExecuteCloudScriptResult : public Wrappers::PFExecuteCloudScriptResultWrapper<Allocator>, public OutputModel<PFExecuteCloudScriptResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExecuteCloudScriptResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExecuteCloudScriptResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExecuteCloudScriptResult& model);
    static HRESULT Copy(const PFExecuteCloudScriptResult& input, PFExecuteCloudScriptResult& output, ModelBuffer& buffer);
};

class NameIdentifier : public Wrappers::PFNameIdentifierWrapper<Allocator>, public InputModel, public OutputModel<PFNameIdentifier>
{
public:
    using ModelWrapperType = typename Wrappers::PFNameIdentifierWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFNameIdentifier& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFNameIdentifier const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFNameIdentifier& model);
    static HRESULT Copy(const PFNameIdentifier& input, PFNameIdentifier& output, ModelBuffer& buffer);
};

class UserDataRecord : public Wrappers::PFUserDataRecordWrapper<Allocator>, public OutputModel<PFUserDataRecord>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserDataRecordWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserDataRecord const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserDataRecord& model);
    static HRESULT Copy(const PFUserDataRecord& input, PFUserDataRecord& output, ModelBuffer& buffer);
};

class PlayerProfileViewConstraints : public Wrappers::PFPlayerProfileViewConstraintsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerProfileViewConstraintsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerProfileViewConstraints& input);

};

class AdCampaignAttributionModel : public Wrappers::PFAdCampaignAttributionModelWrapper<Allocator>, public InputModel, public OutputModel<PFAdCampaignAttributionModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdCampaignAttributionModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAdCampaignAttributionModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdCampaignAttributionModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdCampaignAttributionModel& model);
    static HRESULT Copy(const PFAdCampaignAttributionModel& input, PFAdCampaignAttributionModel& output, ModelBuffer& buffer);
};

class ContactEmailInfoModel : public Wrappers::PFContactEmailInfoModelWrapper<Allocator>, public InputModel, public OutputModel<PFContactEmailInfoModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFContactEmailInfoModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFContactEmailInfoModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFContactEmailInfoModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFContactEmailInfoModel& model);
    static HRESULT Copy(const PFContactEmailInfoModel& input, PFContactEmailInfoModel& output, ModelBuffer& buffer);
};

class LinkedPlatformAccountModel : public Wrappers::PFLinkedPlatformAccountModelWrapper<Allocator>, public InputModel, public OutputModel<PFLinkedPlatformAccountModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFLinkedPlatformAccountModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLinkedPlatformAccountModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLinkedPlatformAccountModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLinkedPlatformAccountModel& model);
    static HRESULT Copy(const PFLinkedPlatformAccountModel& input, PFLinkedPlatformAccountModel& output, ModelBuffer& buffer);
};

class LocationModel : public Wrappers::PFLocationModelWrapper<Allocator>, public InputModel, public OutputModel<PFLocationModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFLocationModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLocationModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLocationModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLocationModel& model);
    static HRESULT Copy(const PFLocationModel& input, PFLocationModel& output, ModelBuffer& buffer);
};

class SubscriptionModel : public Wrappers::PFSubscriptionModelWrapper<Allocator>, public InputModel, public OutputModel<PFSubscriptionModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFSubscriptionModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSubscriptionModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSubscriptionModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSubscriptionModel& model);
    static HRESULT Copy(const PFSubscriptionModel& input, PFSubscriptionModel& output, ModelBuffer& buffer);
};

class MembershipModel : public Wrappers::PFMembershipModelWrapper<Allocator>, public InputModel, public OutputModel<PFMembershipModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFMembershipModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMembershipModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMembershipModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMembershipModel& model);
    static HRESULT Copy(const PFMembershipModel& input, PFMembershipModel& output, ModelBuffer& buffer);
};

class PushNotificationRegistrationModel : public Wrappers::PFPushNotificationRegistrationModelWrapper<Allocator>, public InputModel, public OutputModel<PFPushNotificationRegistrationModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationRegistrationModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationRegistrationModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPushNotificationRegistrationModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPushNotificationRegistrationModel& model);
    static HRESULT Copy(const PFPushNotificationRegistrationModel& input, PFPushNotificationRegistrationModel& output, ModelBuffer& buffer);
};

class StatisticModel : public Wrappers::PFStatisticModelWrapper<Allocator>, public InputModel, public OutputModel<PFStatisticModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFStatisticModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFStatisticModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFStatisticModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFStatisticModel& model);
    static HRESULT Copy(const PFStatisticModel& input, PFStatisticModel& output, ModelBuffer& buffer);
};

class TagModel : public Wrappers::PFTagModelWrapper<Allocator>, public InputModel, public OutputModel<PFTagModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFTagModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTagModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTagModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTagModel& model);
    static HRESULT Copy(const PFTagModel& input, PFTagModel& output, ModelBuffer& buffer);
};

class ValueToDateModel : public Wrappers::PFValueToDateModelWrapper<Allocator>, public InputModel, public OutputModel<PFValueToDateModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFValueToDateModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFValueToDateModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFValueToDateModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFValueToDateModel& model);
    static HRESULT Copy(const PFValueToDateModel& input, PFValueToDateModel& output, ModelBuffer& buffer);
};

class PlayerProfileModel : public Wrappers::PFPlayerProfileModelWrapper<Allocator>, public InputModel, public OutputModel<PFPlayerProfileModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerProfileModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerProfileModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerProfileModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerProfileModel& model);
    static HRESULT Copy(const PFPlayerProfileModel& input, PFPlayerProfileModel& output, ModelBuffer& buffer);
};

class UserFacebookInfo : public Wrappers::PFUserFacebookInfoWrapper<Allocator>, public OutputModel<PFUserFacebookInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserFacebookInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserFacebookInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserFacebookInfo& model);
    static HRESULT Copy(const PFUserFacebookInfo& input, PFUserFacebookInfo& output, ModelBuffer& buffer);
};

class UserGameCenterInfo : public Wrappers::PFUserGameCenterInfoWrapper<Allocator>, public OutputModel<PFUserGameCenterInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserGameCenterInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserGameCenterInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserGameCenterInfo& model);
    static HRESULT Copy(const PFUserGameCenterInfo& input, PFUserGameCenterInfo& output, ModelBuffer& buffer);
};

class UserPsnInfo : public Wrappers::PFUserPsnInfoWrapper<Allocator>, public OutputModel<PFUserPsnInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserPsnInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserPsnInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserPsnInfo& model);
    static HRESULT Copy(const PFUserPsnInfo& input, PFUserPsnInfo& output, ModelBuffer& buffer);
};

class UserSteamInfo : public Wrappers::PFUserSteamInfoWrapper<Allocator>, public OutputModel<PFUserSteamInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserSteamInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserSteamInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserSteamInfo& model);
    static HRESULT Copy(const PFUserSteamInfo& input, PFUserSteamInfo& output, ModelBuffer& buffer);
};

class UserXboxInfo : public Wrappers::PFUserXboxInfoWrapper<Allocator>, public OutputModel<PFUserXboxInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserXboxInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserXboxInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserXboxInfo& model);
    static HRESULT Copy(const PFUserXboxInfo& input, PFUserXboxInfo& output, ModelBuffer& buffer);
};

class CharacterResult : public Wrappers::PFCharacterResultWrapper<Allocator>, public OutputModel<PFCharacterResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterResult& model);
    static HRESULT Copy(const PFCharacterResult& input, PFCharacterResult& output, ModelBuffer& buffer);
};

class VirtualCurrencyRechargeTime : public Wrappers::PFVirtualCurrencyRechargeTimeWrapper<Allocator>, public OutputModel<PFVirtualCurrencyRechargeTime>
{
public:
    using ModelWrapperType = typename Wrappers::PFVirtualCurrencyRechargeTimeWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFVirtualCurrencyRechargeTime const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFVirtualCurrencyRechargeTime& model);
    static HRESULT Copy(const PFVirtualCurrencyRechargeTime& input, PFVirtualCurrencyRechargeTime& output, ModelBuffer& buffer);
};

class StatisticValue : public Wrappers::PFStatisticValueWrapper<Allocator>, public OutputModel<PFStatisticValue>
{
public:
    using ModelWrapperType = typename Wrappers::PFStatisticValueWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFStatisticValue const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFStatisticValue& model);
    static HRESULT Copy(const PFStatisticValue& input, PFStatisticValue& output, ModelBuffer& buffer);
};

class GetPlayerCombinedInfoRequestParams : public Wrappers::PFGetPlayerCombinedInfoRequestParamsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGetPlayerCombinedInfoRequestParamsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGetPlayerCombinedInfoRequestParams& input);

};

class EntityKey : public Wrappers::PFEntityKeyWrapper<Allocator>, public InputModel, public OutputModel<PFEntityKey>
{
public:
    using ModelWrapperType = typename Wrappers::PFEntityKeyWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEntityKey& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEntityKey const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEntityKey& model);
    static HRESULT Copy(const PFEntityKey& input, PFEntityKey& output, ModelBuffer& buffer);
};

class UserAndroidDeviceInfo : public Wrappers::PFUserAndroidDeviceInfoWrapper<Allocator>, public OutputModel<PFUserAndroidDeviceInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserAndroidDeviceInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserAndroidDeviceInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserAndroidDeviceInfo& model);
    static HRESULT Copy(const PFUserAndroidDeviceInfo& input, PFUserAndroidDeviceInfo& output, ModelBuffer& buffer);
};

class UserAppleIdInfo : public Wrappers::PFUserAppleIdInfoWrapper<Allocator>, public OutputModel<PFUserAppleIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserAppleIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserAppleIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserAppleIdInfo& model);
    static HRESULT Copy(const PFUserAppleIdInfo& input, PFUserAppleIdInfo& output, ModelBuffer& buffer);
};

class UserCustomIdInfo : public Wrappers::PFUserCustomIdInfoWrapper<Allocator>, public OutputModel<PFUserCustomIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserCustomIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserCustomIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserCustomIdInfo& model);
    static HRESULT Copy(const PFUserCustomIdInfo& input, PFUserCustomIdInfo& output, ModelBuffer& buffer);
};

class UserFacebookInstantGamesIdInfo : public Wrappers::PFUserFacebookInstantGamesIdInfoWrapper<Allocator>, public OutputModel<PFUserFacebookInstantGamesIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserFacebookInstantGamesIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserFacebookInstantGamesIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserFacebookInstantGamesIdInfo& model);
    static HRESULT Copy(const PFUserFacebookInstantGamesIdInfo& input, PFUserFacebookInstantGamesIdInfo& output, ModelBuffer& buffer);
};

class UserGoogleInfo : public Wrappers::PFUserGoogleInfoWrapper<Allocator>, public OutputModel<PFUserGoogleInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserGoogleInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserGoogleInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserGoogleInfo& model);
    static HRESULT Copy(const PFUserGoogleInfo& input, PFUserGoogleInfo& output, ModelBuffer& buffer);
};

class UserIosDeviceInfo : public Wrappers::PFUserIosDeviceInfoWrapper<Allocator>, public OutputModel<PFUserIosDeviceInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserIosDeviceInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserIosDeviceInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserIosDeviceInfo& model);
    static HRESULT Copy(const PFUserIosDeviceInfo& input, PFUserIosDeviceInfo& output, ModelBuffer& buffer);
};

class UserKongregateInfo : public Wrappers::PFUserKongregateInfoWrapper<Allocator>, public OutputModel<PFUserKongregateInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserKongregateInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserKongregateInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserKongregateInfo& model);
    static HRESULT Copy(const PFUserKongregateInfo& input, PFUserKongregateInfo& output, ModelBuffer& buffer);
};

class UserNintendoSwitchAccountIdInfo : public Wrappers::PFUserNintendoSwitchAccountIdInfoWrapper<Allocator>, public OutputModel<PFUserNintendoSwitchAccountIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserNintendoSwitchAccountIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserNintendoSwitchAccountIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserNintendoSwitchAccountIdInfo& model);
    static HRESULT Copy(const PFUserNintendoSwitchAccountIdInfo& input, PFUserNintendoSwitchAccountIdInfo& output, ModelBuffer& buffer);
};

class UserNintendoSwitchDeviceIdInfo : public Wrappers::PFUserNintendoSwitchDeviceIdInfoWrapper<Allocator>, public OutputModel<PFUserNintendoSwitchDeviceIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserNintendoSwitchDeviceIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserNintendoSwitchDeviceIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserNintendoSwitchDeviceIdInfo& model);
    static HRESULT Copy(const PFUserNintendoSwitchDeviceIdInfo& input, PFUserNintendoSwitchDeviceIdInfo& output, ModelBuffer& buffer);
};

class UserOpenIdInfo : public Wrappers::PFUserOpenIdInfoWrapper<Allocator>, public OutputModel<PFUserOpenIdInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserOpenIdInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserOpenIdInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserOpenIdInfo& model);
    static HRESULT Copy(const PFUserOpenIdInfo& input, PFUserOpenIdInfo& output, ModelBuffer& buffer);
};

class UserPrivateAccountInfo : public Wrappers::PFUserPrivateAccountInfoWrapper<Allocator>, public OutputModel<PFUserPrivateAccountInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserPrivateAccountInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserPrivateAccountInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserPrivateAccountInfo& model);
    static HRESULT Copy(const PFUserPrivateAccountInfo& input, PFUserPrivateAccountInfo& output, ModelBuffer& buffer);
};

class UserTitleInfo : public Wrappers::PFUserTitleInfoWrapper<Allocator>, public OutputModel<PFUserTitleInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserTitleInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserTitleInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserTitleInfo& model);
    static HRESULT Copy(const PFUserTitleInfo& input, PFUserTitleInfo& output, ModelBuffer& buffer);
};

class UserTwitchInfo : public Wrappers::PFUserTwitchInfoWrapper<Allocator>, public OutputModel<PFUserTwitchInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserTwitchInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserTwitchInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserTwitchInfo& model);
    static HRESULT Copy(const PFUserTwitchInfo& input, PFUserTwitchInfo& output, ModelBuffer& buffer);
};

class UserAccountInfo : public Wrappers::PFUserAccountInfoWrapper<Allocator>, public OutputModel<PFUserAccountInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFUserAccountInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFUserAccountInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFUserAccountInfo& model);
    static HRESULT Copy(const PFUserAccountInfo& input, PFUserAccountInfo& output, ModelBuffer& buffer);
};

class CharacterInventory : public Wrappers::PFCharacterInventoryWrapper<Allocator>, public OutputModel<PFCharacterInventory>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterInventoryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterInventory const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterInventory& model);
    static HRESULT Copy(const PFCharacterInventory& input, PFCharacterInventory& output, ModelBuffer& buffer);
};

class GetPlayerCombinedInfoResultPayload : public Wrappers::PFGetPlayerCombinedInfoResultPayloadWrapper<Allocator>, public OutputModel<PFGetPlayerCombinedInfoResultPayload>
{
public:
    using ModelWrapperType = typename Wrappers::PFGetPlayerCombinedInfoResultPayloadWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGetPlayerCombinedInfoResultPayload const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGetPlayerCombinedInfoResultPayload& model);
    static HRESULT Copy(const PFGetPlayerCombinedInfoResultPayload& input, PFGetPlayerCombinedInfoResultPayload& output, ModelBuffer& buffer);
};

class GetPlayerCombinedInfoRequest : public Wrappers::PFGetPlayerCombinedInfoRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGetPlayerCombinedInfoRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGetPlayerCombinedInfoRequest& input);

};

class GetPlayerCombinedInfoResult : public Wrappers::PFGetPlayerCombinedInfoResultWrapper<Allocator>, public OutputModel<PFGetPlayerCombinedInfoResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGetPlayerCombinedInfoResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGetPlayerCombinedInfoResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGetPlayerCombinedInfoResult& model);
    static HRESULT Copy(const PFGetPlayerCombinedInfoResult& input, PFGetPlayerCombinedInfoResult& output, ModelBuffer& buffer);
};

class ResultTableNode : public Wrappers::PFResultTableNodeWrapper<Allocator>, public InputModel, public OutputModel<PFResultTableNode>
{
public:
    using ModelWrapperType = typename Wrappers::PFResultTableNodeWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFResultTableNode& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFResultTableNode const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFResultTableNode& model);
    static HRESULT Copy(const PFResultTableNode& input, PFResultTableNode& output, ModelBuffer& buffer);
};

class RandomResultTableListing : public Wrappers::PFRandomResultTableListingWrapper<Allocator>, public OutputModel<PFRandomResultTableListing>
{
public:
    using ModelWrapperType = typename Wrappers::PFRandomResultTableListingWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFRandomResultTableListing const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFRandomResultTableListing& model);
    static HRESULT Copy(const PFRandomResultTableListing& input, PFRandomResultTableListing& output, ModelBuffer& buffer);
};

class GetRandomResultTablesResult : public Wrappers::PFGetRandomResultTablesResultWrapper<Allocator>, public OutputModel<PFGetRandomResultTablesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGetRandomResultTablesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGetRandomResultTablesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGetRandomResultTablesResult& model);
    static HRESULT Copy(const PFGetRandomResultTablesResult& input, PFGetRandomResultTablesResult& output, ModelBuffer& buffer);
};

class Variable : public Wrappers::PFVariableWrapper<Allocator>, public InputModel, public OutputModel<PFVariable>
{
public:
    using ModelWrapperType = typename Wrappers::PFVariableWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFVariable& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFVariable const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFVariable& model);
    static HRESULT Copy(const PFVariable& input, PFVariable& output, ModelBuffer& buffer);
};

class TreatmentAssignment : public Wrappers::PFTreatmentAssignmentWrapper<Allocator>, public OutputModel<PFTreatmentAssignment>
{
public:
    using ModelWrapperType = typename Wrappers::PFTreatmentAssignmentWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTreatmentAssignment const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTreatmentAssignment& model);
    static HRESULT Copy(const PFTreatmentAssignment& input, PFTreatmentAssignment& output, ModelBuffer& buffer);
};

class Port : public Wrappers::PFPortWrapper<Allocator>, public InputModel, public OutputModel<PFPort>
{
public:
    using ModelWrapperType = typename Wrappers::PFPortWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPort& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPort const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPort& model);
    static HRESULT Copy(const PFPort& input, PFPort& output, ModelBuffer& buffer);
};

class EntityLineage : public Wrappers::PFEntityLineageWrapper<Allocator>, public OutputModel<PFEntityLineage>
{
public:
    using ModelWrapperType = typename Wrappers::PFEntityLineageWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEntityLineage const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEntityLineage& model);
    static HRESULT Copy(const PFEntityLineage& input, PFEntityLineage& output, ModelBuffer& buffer);
};

// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
