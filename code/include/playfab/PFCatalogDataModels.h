// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// ModerationStatus enum.
/// </summary>
enum class PFCatalogModerationStatus : uint32_t
{
    Unknown,
    AwaitingModeration,
    Approved,
    Rejected
};

/// <summary>
/// DisplayPropertyType enum.
/// </summary>
enum class PFCatalogDisplayPropertyType : uint32_t
{
    None,
    QueryDateTime,
    QueryDouble,
    QueryString,
    SearchString
};

/// <summary>
/// PublishResult enum.
/// </summary>
enum class PFCatalogPublishResult : uint32_t
{
    Unknown,
    Pending,
    Succeeded,
    Failed,
    Canceled
};

/// <summary>
/// ConcernCategory enum.
/// </summary>
enum class PFCatalogConcernCategory : uint32_t
{
    None,
    OffensiveContent,
    ChildExploitation,
    MalwareOrVirus,
    PrivacyConcerns,
    MisleadingApp,
    PoorPerformance,
    ReviewResponse,
    SpamAdvertising,
    Profanity
};

/// <summary>
/// HelpfulnessVote enum.
/// </summary>
enum class PFCatalogHelpfulnessVote : uint32_t
{
    None,
    UnHelpful,
    Helpful
};

/// <summary>
/// PFCatalogCatalogAlternateId data model.
/// </summary>
typedef struct PFCatalogCatalogAlternateId
{
    /// <summary>
    /// (Optional) Type of the alternate ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

    /// <summary>
    /// (Optional) Value of the alternate ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFCatalogCatalogAlternateId;

/// <summary>
/// PFCatalogContent data model.
/// </summary>
typedef struct PFCatalogContent
{
    /// <summary>
    /// (Optional) The content unique ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The maximum client version that this content is compatible with.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* maxClientVersion;

    /// <summary>
    /// (Optional) The minimum client version that this content is compatible with.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* minClientVersion;

    /// <summary>
    /// (Optional) The Azure CDN URL for retrieval of the catalog item binary content.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* url;

} PFCatalogContent;

/// <summary>
/// PFCatalogImage data model.
/// </summary>
typedef struct PFCatalogImage
{
    /// <summary>
    /// (Optional) The image unique ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The client-defined type of this image.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

    /// <summary>
    /// (Optional) The URL for retrieval of the image.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* url;

} PFCatalogImage;

/// <summary>
/// PFCatalogKeywordSet data model.
/// </summary>
typedef struct PFCatalogKeywordSet
{
    /// <summary>
    /// (Optional) A list of localized keywords.
    /// </summary>
    _Maybenull_ _Field_size_(valuesCount) const char* const* values;

    /// <summary>
    /// Count of values
    /// </summary>
    uint32_t valuesCount;

} PFCatalogKeywordSet;

/// <summary>
/// PFCatalogModerationState data model.
/// </summary>
typedef struct PFCatalogModerationState
{
    /// <summary>
    /// (Optional) The date and time this moderation state was last updated.
    /// </summary>
    _Maybenull_ time_t const* lastModifiedDate;

    /// <summary>
    /// (Optional) The current stated reason for the associated item being moderated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

    /// <summary>
    /// (Optional) The current moderation status for the associated item.
    /// </summary>
    _Maybenull_ PFCatalogModerationStatus const* status;

} PFCatalogModerationState;

/// <summary>
/// PFCatalogRating data model.
/// </summary>
typedef struct PFCatalogRating
{
    /// <summary>
    /// (Optional) The average rating for this item.
    /// </summary>
    _Maybenull_ float const* average;

    /// <summary>
    /// (Optional) The total count of 1 star ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* count1Star;

    /// <summary>
    /// (Optional) The total count of 2 star ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* count2Star;

    /// <summary>
    /// (Optional) The total count of 3 star ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* count3Star;

    /// <summary>
    /// (Optional) The total count of 4 star ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* count4Star;

    /// <summary>
    /// (Optional) The total count of 5 star ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* count5Star;

    /// <summary>
    /// (Optional) The total count of ratings for this item.
    /// </summary>
    _Maybenull_ int32_t const* totalCount;

} PFCatalogRating;

/// <summary>
/// PFCatalogCatalogItem data model.
/// </summary>
typedef struct PFCatalogCatalogItem
{
    /// <summary>
    /// (Optional) The alternate IDs associated with this item.
    /// </summary>
    _Maybenull_ _Field_size_(alternateIdsCount) PFCatalogCatalogAlternateId const* const* alternateIds;

    /// <summary>
    /// Count of alternateIds
    /// </summary>
    uint32_t alternateIdsCount;

    /// <summary>
    /// (Optional) The set of contents associated with this item.
    /// </summary>
    _Maybenull_ _Field_size_(contentsCount) PFCatalogContent const* const* contents;

    /// <summary>
    /// Count of contents
    /// </summary>
    uint32_t contentsCount;

    /// <summary>
    /// (Optional) The client-defined type of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* contentType;

    /// <summary>
    /// (Optional) The date and time when this item was created.
    /// </summary>
    _Maybenull_ time_t const* creationDate;

    /// <summary>
    /// (Optional) The ID of the creator of this catalog item.
    /// </summary>
    _Maybenull_ PFEntityKey const* creatorEntity;

    /// <summary>
    /// (Optional) A dictionary of localized descriptions. Key is language code and localized string
    /// is the value. The neutral locale is required.
    /// </summary>
    _Maybenull_ _Field_size_(descriptionCount) struct PFStringDictionaryEntry const* description;

    /// <summary>
    /// Count of description
    /// </summary>
    uint32_t descriptionCount;

    /// <summary>
    /// (Optional) Game specific properties for display purposes. This is an arbitrary JSON blob.
    /// </summary>
    PFJsonObject displayProperties;

    /// <summary>
    /// (Optional) The user provided version of the item for display purposes.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayVersion;

    /// <summary>
    /// (Optional) The date of when the item will cease to be available. If not provided then the product
    /// will be available indefinitely.
    /// </summary>
    _Maybenull_ time_t const* endDate;

    /// <summary>
    /// (Optional) The current ETag value that can be used for optimistic concurrency in the If-None-Match
    /// header.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eTag;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The images associated with this item. Images can be thumbnails or screenshots.
    /// </summary>
    _Maybenull_ _Field_size_(imagesCount) PFCatalogImage const* const* images;

    /// <summary>
    /// Count of images
    /// </summary>
    uint32_t imagesCount;

    /// <summary>
    /// (Optional) Indicates if the item is hidden.
    /// </summary>
    _Maybenull_ bool const* isHidden;

    /// <summary>
    /// (Optional) A dictionary of localized keywords. Key is language code and localized list of keywords
    /// is the value.
    /// </summary>
    _Maybenull_ _Field_size_(keywordsCount) struct PFCatalogKeywordSetDictionaryEntry const* keywords;

    /// <summary>
    /// Count of keywords
    /// </summary>
    uint32_t keywordsCount;

    /// <summary>
    /// (Optional) The date and time this item was last updated.
    /// </summary>
    _Maybenull_ time_t const* lastModifiedDate;

    /// <summary>
    /// (Optional) The moderation state for this item.
    /// </summary>
    _Maybenull_ PFCatalogModerationState const* moderation;

    /// <summary>
    /// (Optional) Rating summary for this item.
    /// </summary>
    _Maybenull_ PFCatalogRating const* rating;

    /// <summary>
    /// (Optional) The date of when the item will be available. If not provided then the product will
    /// appear immediately.
    /// </summary>
    _Maybenull_ time_t const* startDate;

    /// <summary>
    /// (Optional) The list of tags that are associated with this item.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) const char* const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

    /// <summary>
    /// (Optional) A dictionary of localized titles. Key is language code and localized string is the
    /// value. The neutral locale is required.
    /// </summary>
    _Maybenull_ _Field_size_(titleCount) struct PFStringDictionaryEntry const* title;

    /// <summary>
    /// Count of title
    /// </summary>
    uint32_t titleCount;

    /// <summary>
    /// (Optional) The high-level type of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

} PFCatalogCatalogItem;

/// <summary>
/// PFCatalogCreateDraftItemRequest data model. The item will not be published to the public catalog
/// until the PublishItem API is called for the item.
/// </summary>
typedef struct PFCatalogCreateDraftItemRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Metadata describing the new catalog item to be created.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

    /// <summary>
    /// Whether the item should be published immediately.
    /// </summary>
    bool publish;

} PFCatalogCreateDraftItemRequest;

/// <summary>
/// PFCatalogCreateDraftItemResponse data model.
/// </summary>
typedef struct PFCatalogCreateDraftItemResponse
{
    /// <summary>
    /// (Optional) Updated metadata describing the catalog item just created.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

} PFCatalogCreateDraftItemResponse;

/// <summary>
/// PFCatalogUploadInfo data model.
/// </summary>
typedef struct PFCatalogUploadInfo
{
    /// <summary>
    /// (Optional) Name of the file to be uploaded.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

} PFCatalogUploadInfo;

/// <summary>
/// PFCatalogCreateUploadUrlsRequest data model. Upload URLs point to Azure Blobs; clients must follow
/// the Microsoft Azure Storage Blob Service REST API pattern for uploading content. The response contains
/// upload URLs and IDs for each file. The IDs and URLs returned must be added to the item metadata and
/// committed using the CreateDraftItem or UpdateDraftItem Item APIs.
/// </summary>
typedef struct PFCatalogCreateUploadUrlsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Description of the files to be uploaded by the client.
    /// </summary>
    _Maybenull_ _Field_size_(filesCount) PFCatalogUploadInfo const* const* files;

    /// <summary>
    /// Count of files
    /// </summary>
    uint32_t filesCount;

} PFCatalogCreateUploadUrlsRequest;

/// <summary>
/// PFCatalogUploadUrlMetadata data model.
/// </summary>
typedef struct PFCatalogUploadUrlMetadata
{
    /// <summary>
    /// (Optional) Name of the file for which this upload URL was requested.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

    /// <summary>
    /// (Optional) Unique ID for the binary content to be uploaded to the target URL.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) URL for the binary content to be uploaded to.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* url;

} PFCatalogUploadUrlMetadata;

/// <summary>
/// PFCatalogCreateUploadUrlsResponse data model.
/// </summary>
typedef struct PFCatalogCreateUploadUrlsResponse
{
    /// <summary>
    /// (Optional) List of URLs metadata for the files to be uploaded by the client.
    /// </summary>
    _Maybenull_ _Field_size_(uploadUrlsCount) PFCatalogUploadUrlMetadata const* const* uploadUrls;

    /// <summary>
    /// Count of uploadUrls
    /// </summary>
    uint32_t uploadUrlsCount;

} PFCatalogCreateUploadUrlsResponse;

/// <summary>
/// PFCatalogDeleteEntityItemReviewsRequest data model.
/// </summary>
typedef struct PFCatalogDeleteEntityItemReviewsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFCatalogDeleteEntityItemReviewsRequest;

/// <summary>
/// PFCatalogDeleteItemRequest data model.
/// </summary>
typedef struct PFCatalogDeleteItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogDeleteItemRequest;

/// <summary>
/// PFCatalogGetCatalogConfigRequest data model.
/// </summary>
typedef struct PFCatalogGetCatalogConfigRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFCatalogGetCatalogConfigRequest;

/// <summary>
/// PFCatalogDisplayPropertyIndexInfo data model.
/// </summary>
typedef struct PFCatalogDisplayPropertyIndexInfo
{
    /// <summary>
    /// (Optional) The property name in the 'DisplayProperties' property to be indexed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) The type of the property to be indexed.
    /// </summary>
    _Maybenull_ PFCatalogDisplayPropertyType const* type;

} PFCatalogDisplayPropertyIndexInfo;

/// <summary>
/// PFCatalogUserGeneratedContentSpecificConfig data model.
/// </summary>
typedef struct PFCatalogUserGeneratedContentSpecificConfig
{
    /// <summary>
    /// (Optional) The set of content types that will be used for validation and if no values are provided
    /// then anything is allowed.
    /// </summary>
    _Maybenull_ _Field_size_(contentTypesCount) const char* const* contentTypes;

    /// <summary>
    /// Count of contentTypes
    /// </summary>
    uint32_t contentTypesCount;

    /// <summary>
    /// (Optional) The set of tags that will be used for validation and if no values are provided then
    /// anything is allowed.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) const char* const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFCatalogUserGeneratedContentSpecificConfig;

/// <summary>
/// PFCatalogCatalogConfig data model.
/// </summary>
typedef struct PFCatalogCatalogConfig
{
    /// <summary>
    /// (Optional) A list of player entity keys that will have admin permissions.
    /// </summary>
    _Maybenull_ _Field_size_(adminEntitiesCount) PFEntityKey const* const* adminEntities;

    /// <summary>
    /// Count of adminEntities
    /// </summary>
    uint32_t adminEntitiesCount;

    /// <summary>
    /// (Optional) A list of display properties to index.
    /// </summary>
    _Maybenull_ _Field_size_(displayPropertyIndexInfosCount) PFCatalogDisplayPropertyIndexInfo const* const* displayPropertyIndexInfos;

    /// <summary>
    /// Count of displayPropertyIndexInfos
    /// </summary>
    uint32_t displayPropertyIndexInfosCount;

    /// <summary>
    /// Flag defining whether catalog is enabled.
    /// </summary>
    bool isCatalogEnabled;

    /// <summary>
    /// (Optional) A set of player entity keys that are allowed to review content.
    /// </summary>
    _Maybenull_ _Field_size_(reviewerEntitiesCount) PFEntityKey const* const* reviewerEntities;

    /// <summary>
    /// Count of reviewerEntities
    /// </summary>
    uint32_t reviewerEntitiesCount;

    /// <summary>
    /// (Optional) The set of configuration that only applies to user generated contents.
    /// </summary>
    _Maybenull_ PFCatalogUserGeneratedContentSpecificConfig const* userGeneratedContent;

} PFCatalogCatalogConfig;

/// <summary>
/// PFCatalogGetCatalogConfigResponse data model.
/// </summary>
typedef struct PFCatalogGetCatalogConfigResponse
{
    /// <summary>
    /// (Optional) The catalog configuration.
    /// </summary>
    _Maybenull_ PFCatalogCatalogConfig const* config;

} PFCatalogGetCatalogConfigResponse;

/// <summary>
/// PFCatalogGetDraftItemRequest data model.
/// </summary>
typedef struct PFCatalogGetDraftItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetDraftItemRequest;

/// <summary>
/// PFCatalogGetDraftItemResponse data model.
/// </summary>
typedef struct PFCatalogGetDraftItemResponse
{
    /// <summary>
    /// (Optional) Full metadata of the catalog item requested.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

} PFCatalogGetDraftItemResponse;

/// <summary>
/// PFCatalogGetDraftItemsRequest data model.
/// </summary>
typedef struct PFCatalogGetDraftItemsRequest
{
    /// <summary>
    /// (Optional) List of item alternate IDs.
    /// </summary>
    _Maybenull_ _Field_size_(alternateIdsCount) PFCatalogCatalogAlternateId const* const* alternateIds;

    /// <summary>
    /// Count of alternateIds
    /// </summary>
    uint32_t alternateIdsCount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) List of Item Ids.
    /// </summary>
    _Maybenull_ _Field_size_(idsCount) const char* const* ids;

    /// <summary>
    /// Count of ids
    /// </summary>
    uint32_t idsCount;

} PFCatalogGetDraftItemsRequest;

/// <summary>
/// PFCatalogGetDraftItemsResponse data model.
/// </summary>
typedef struct PFCatalogGetDraftItemsResponse
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) A set of items created by the entity.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFCatalogCatalogItem const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFCatalogGetDraftItemsResponse;

/// <summary>
/// PFCatalogGetEntityDraftItemsRequest data model.
/// </summary>
typedef struct PFCatalogGetEntityDraftItemsRequest
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items created by the caller, if
    /// any are available. Should be null on initial request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// Number of items to retrieve. Maximum page size is 10.
    /// </summary>
    int32_t count;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFCatalogGetEntityDraftItemsRequest;

/// <summary>
/// PFCatalogGetEntityDraftItemsResponse data model.
/// </summary>
typedef struct PFCatalogGetEntityDraftItemsResponse
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) A set of items created by the entity.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFCatalogCatalogItem const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFCatalogGetEntityDraftItemsResponse;

/// <summary>
/// PFCatalogGetEntityItemReviewRequest data model.
/// </summary>
typedef struct PFCatalogGetEntityItemReviewRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetEntityItemReviewRequest;

/// <summary>
/// PFCatalogReview data model.
/// </summary>
typedef struct PFCatalogReview
{
    /// <summary>
    /// The number of negative helpfulness votes for this review.
    /// </summary>
    int32_t helpfulNegative;

    /// <summary>
    /// Total number of helpfulness votes for this review.
    /// </summary>
    int32_t helpfulnessVotes;

    /// <summary>
    /// The number of positive helpfulness votes for this review.
    /// </summary>
    int32_t helpfulPositive;

    /// <summary>
    /// Indicates whether the review author has the item installed.
    /// </summary>
    bool isInstalled;

    /// <summary>
    /// (Optional) The ID of the item being reviewed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) The version of the item being reviewed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemVersion;

    /// <summary>
    /// (Optional) The locale for which this review was submitted in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* locale;

    /// <summary>
    /// Star rating associated with this review.
    /// </summary>
    int32_t rating;

    /// <summary>
    /// (Optional) The ID of the author of the review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewerId;

    /// <summary>
    /// (Optional) The ID of the review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewId;

    /// <summary>
    /// (Optional) The full text of this review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewText;

    /// <summary>
    /// The date and time this review was last submitted.
    /// </summary>
    time_t submitted;

    /// <summary>
    /// (Optional) The title of this review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* title;

} PFCatalogReview;

/// <summary>
/// PFCatalogGetEntityItemReviewResponse data model.
/// </summary>
typedef struct PFCatalogGetEntityItemReviewResponse
{
    /// <summary>
    /// (Optional) The review the entity submitted for the requested item.
    /// </summary>
    _Maybenull_ PFCatalogReview const* review;

} PFCatalogGetEntityItemReviewResponse;

/// <summary>
/// PFCatalogGetItemRequest data model.
/// </summary>
typedef struct PFCatalogGetItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetItemRequest;

/// <summary>
/// PFCatalogGetItemResponse data model. Get item result.
/// </summary>
typedef struct PFCatalogGetItemResponse
{
    /// <summary>
    /// (Optional) The item result.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

} PFCatalogGetItemResponse;

/// <summary>
/// PFCatalogGetItemModerationStateRequest data model.
/// </summary>
typedef struct PFCatalogGetItemModerationStateRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetItemModerationStateRequest;

/// <summary>
/// PFCatalogGetItemModerationStateResponse data model.
/// </summary>
typedef struct PFCatalogGetItemModerationStateResponse
{
    /// <summary>
    /// (Optional) The current moderation state for the requested item.
    /// </summary>
    _Maybenull_ PFCatalogModerationState const* state;

} PFCatalogGetItemModerationStateResponse;

/// <summary>
/// PFCatalogGetItemPublishStatusRequest data model.
/// </summary>
typedef struct PFCatalogGetItemPublishStatusRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetItemPublishStatusRequest;

/// <summary>
/// PFCatalogScanResult data model.
/// </summary>
typedef struct PFCatalogScanResult
{
    /// <summary>
    /// (Optional) The URL of the item which failed the scan.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* url;

} PFCatalogScanResult;

/// <summary>
/// PFCatalogGetItemPublishStatusResponse data model.
/// </summary>
typedef struct PFCatalogGetItemPublishStatusResponse
{
    /// <summary>
    /// (Optional) Scan results for any items that failed content scans.
    /// </summary>
    _Maybenull_ _Field_size_(failedScanResultsCount) PFCatalogScanResult const* const* failedScanResults;

    /// <summary>
    /// Count of failedScanResults
    /// </summary>
    uint32_t failedScanResultsCount;

    /// <summary>
    /// (Optional) High level status of the published item.
    /// </summary>
    _Maybenull_ PFCatalogPublishResult const* result;

    /// <summary>
    /// (Optional) Descriptive message about the current status of the publish.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statusMessage;

} PFCatalogGetItemPublishStatusResponse;

/// <summary>
/// PFCatalogGetItemReviewsRequest data model.
/// </summary>
typedef struct PFCatalogGetItemReviewsRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// Number of items to retrieve. Maximum page size is 200. If not specified, defaults to 10.
    /// </summary>
    int32_t count;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) An OData orderBy used to order the results of the query.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderBy;

} PFCatalogGetItemReviewsRequest;

/// <summary>
/// PFCatalogGetItemReviewsResponse data model.
/// </summary>
typedef struct PFCatalogGetItemReviewsResponse
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) The paginated set of results.
    /// </summary>
    _Maybenull_ _Field_size_(reviewsCount) PFCatalogReview const* const* reviews;

    /// <summary>
    /// Count of reviews
    /// </summary>
    uint32_t reviewsCount;

} PFCatalogGetItemReviewsResponse;

/// <summary>
/// PFCatalogGetItemReviewSummaryRequest data model.
/// </summary>
typedef struct PFCatalogGetItemReviewSummaryRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogGetItemReviewSummaryRequest;

/// <summary>
/// PFCatalogGetItemReviewSummaryResponse data model.
/// </summary>
typedef struct PFCatalogGetItemReviewSummaryResponse
{
    /// <summary>
    /// (Optional) The least favorable review for this item.
    /// </summary>
    _Maybenull_ PFCatalogReview const* leastFavorableReview;

    /// <summary>
    /// (Optional) The most favorable review for this item.
    /// </summary>
    _Maybenull_ PFCatalogReview const* mostFavorableReview;

    /// <summary>
    /// (Optional) The summary of ratings associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogRating const* rating;

    /// <summary>
    /// The total number of reviews associated with this item.
    /// </summary>
    int32_t reviewsCount;

} PFCatalogGetItemReviewSummaryResponse;

/// <summary>
/// PFCatalogPublishDraftItemRequest data model. The call kicks off a workflow to publish the item to
/// the public catalog. The Publish Status API should be used to monitor the publish job.
/// </summary>
typedef struct PFCatalogPublishDraftItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) ETag of the catalog item to published from the working catalog to the public catalog.
    /// Used for optimistic concurrency. If the provided ETag does not match the ETag in the current working
    /// catalog, the request will be rejected. If not provided, the current version of the document in
    /// the working catalog will be published.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eTag;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

} PFCatalogPublishDraftItemRequest;

/// <summary>
/// PFCatalogReportItemRequest data model.
/// </summary>
typedef struct PFCatalogReportItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) Category of concern for this report.
    /// </summary>
    _Maybenull_ PFCatalogConcernCategory const* concernCategory;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The string reason for this report.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFCatalogReportItemRequest;

/// <summary>
/// PFCatalogReportItemReviewRequest data model. Submit a report for an inappropriate review, allowing
/// the submitting user to specify their concern.
/// </summary>
typedef struct PFCatalogReportItemReviewRequest
{
    /// <summary>
    /// (Optional) An alternate ID of the item associated with the review.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The reason this review is being reported.
    /// </summary>
    _Maybenull_ PFCatalogConcernCategory const* concernCategory;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The string ID of the item associated with the review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) The string reason for this report.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

    /// <summary>
    /// (Optional) The ID of the review to submit a report for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewId;

} PFCatalogReportItemReviewRequest;

/// <summary>
/// PFCatalogReviewItemRequest data model.
/// </summary>
typedef struct PFCatalogReviewItemRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The review to submit.
    /// </summary>
    _Maybenull_ PFCatalogReview const* review;

} PFCatalogReviewItemRequest;

/// <summary>
/// PFCatalogSearchItemsRequest data model.
/// </summary>
typedef struct PFCatalogSearchItemsRequest
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// Number of items to retrieve. Maximum page size is 225. Default value is 10.
    /// </summary>
    int32_t count;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) An OData filter used to refine the search query.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* filter;

    /// <summary>
    /// (Optional) An OData orderBy used to order the results of the search query.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderBy;

    /// <summary>
    /// (Optional) The text to search for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* search;

    /// <summary>
    /// (Optional) An OData select query option used to augment the search results. If not defined, the
    /// default search result metadata will be returned.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* select;

} PFCatalogSearchItemsRequest;

/// <summary>
/// PFCatalogSearchItemsResponse data model.
/// </summary>
typedef struct PFCatalogSearchItemsResponse
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) The paginated set of results for the search query.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFCatalogCatalogItem const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFCatalogSearchItemsResponse;

/// <summary>
/// PFCatalogSetItemModerationStateRequest data model.
/// </summary>
typedef struct PFCatalogSetItemModerationStateRequest
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The unique ID of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The reason for the moderation state change for the associated item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

    /// <summary>
    /// (Optional) The status to set for the associated item.
    /// </summary>
    _Maybenull_ PFCatalogModerationStatus const* status;

} PFCatalogSetItemModerationStateRequest;

/// <summary>
/// PFCatalogSubmitItemReviewVoteRequest data model.
/// </summary>
typedef struct PFCatalogSubmitItemReviewVoteRequest
{
    /// <summary>
    /// (Optional) An alternate ID of the item associated with the review.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The string ID of the item associated with the review.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) The ID of the review to submit a helpfulness vote for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewId;

    /// <summary>
    /// (Optional) The helpfulness vote of the review.
    /// </summary>
    _Maybenull_ PFCatalogHelpfulnessVote const* vote;

} PFCatalogSubmitItemReviewVoteRequest;

/// <summary>
/// PFCatalogReviewTakedown data model.
/// </summary>
typedef struct PFCatalogReviewTakedown
{
    /// <summary>
    /// (Optional) An alternate ID associated with this item.
    /// </summary>
    _Maybenull_ PFCatalogCatalogAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The ID of the item associated with the review to take down.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) The ID of the review to take down.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewId;

} PFCatalogReviewTakedown;

/// <summary>
/// PFCatalogTakedownItemReviewsRequest data model. Submit a request to takedown one or more reviews,
/// removing them from public view. Authors will still be able to see their reviews after being taken
/// down.
/// </summary>
typedef struct PFCatalogTakedownItemReviewsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The set of reviews to take down.
    /// </summary>
    _Maybenull_ _Field_size_(reviewsCount) PFCatalogReviewTakedown const* const* reviews;

    /// <summary>
    /// Count of reviews
    /// </summary>
    uint32_t reviewsCount;

} PFCatalogTakedownItemReviewsRequest;

/// <summary>
/// PFCatalogUpdateCatalogConfigRequest data model.
/// </summary>
typedef struct PFCatalogUpdateCatalogConfigRequest
{
    /// <summary>
    /// (Optional) The updated catalog configuration.
    /// </summary>
    _Maybenull_ PFCatalogCatalogConfig const* config;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFCatalogUpdateCatalogConfigRequest;

/// <summary>
/// PFCatalogUpdateDraftItemRequest data model.
/// </summary>
typedef struct PFCatalogUpdateDraftItemRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Updated metadata describing the catalog item to be updated.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

    /// <summary>
    /// Whether the item should be published immediately.
    /// </summary>
    bool publish;

} PFCatalogUpdateDraftItemRequest;

/// <summary>
/// PFCatalogUpdateDraftItemResponse data model.
/// </summary>
typedef struct PFCatalogUpdateDraftItemResponse
{
    /// <summary>
    /// (Optional) Updated metadata describing the catalog item just updated.
    /// </summary>
    _Maybenull_ PFCatalogCatalogItem const* item;

} PFCatalogUpdateDraftItemResponse;

/// <summary>
/// Dictionary entry for an associative array with PFCatalogKeywordSet values.
/// </summary>
typedef struct PFCatalogKeywordSetDictionaryEntry
{
    _Null_terminated_ const char* key;
    PFCatalogKeywordSet const* value;
} PFCatalogKeywordSetDictionaryEntry;

#pragma pop_macro("IN")

}
