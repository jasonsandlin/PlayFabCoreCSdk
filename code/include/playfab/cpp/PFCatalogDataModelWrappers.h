// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFCatalogDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCatalogAlternateIdWrapper : public ModelWrapper<PFCatalogCatalogAlternateId, Alloc>
{
public:
    using ModelType = typename PFCatalogCatalogAlternateId;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCatalogAlternateIdWrapper() = default;

    PFCatalogCatalogAlternateIdWrapper(const PFCatalogCatalogAlternateId& model) :
        ModelWrapper<PFCatalogCatalogAlternateId, Alloc>{ model },
        m_type{ SafeString(model.type) },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFCatalogCatalogAlternateIdWrapper(const PFCatalogCatalogAlternateIdWrapper& src) :
        PFCatalogCatalogAlternateIdWrapper{ src.Model() }
    {
    }

    PFCatalogCatalogAlternateIdWrapper(PFCatalogCatalogAlternateIdWrapper&& src) :
        PFCatalogCatalogAlternateIdWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCatalogAlternateIdWrapper& operator=(PFCatalogCatalogAlternateIdWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCatalogAlternateIdWrapper() = default;

    friend void swap(PFCatalogCatalogAlternateIdWrapper& lhs, PFCatalogCatalogAlternateIdWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_type, rhs.m_type);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetType(String value)
    {
        m_type = std::move(value);
        this->m_model.type =  m_type.empty() ? nullptr : m_type.data();
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.type = m_type.empty() ? nullptr : m_type.data();
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_type;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogContentWrapper : public ModelWrapper<PFCatalogContent, Alloc>
{
public:
    using ModelType = typename PFCatalogContent;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogContentWrapper() = default;

    PFCatalogContentWrapper(const PFCatalogContent& model) :
        ModelWrapper<PFCatalogContent, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_maxClientVersion{ SafeString(model.maxClientVersion) },
        m_minClientVersion{ SafeString(model.minClientVersion) },
        m_url{ SafeString(model.url) }
    {
        SetModelPointers();
    }

    PFCatalogContentWrapper(const PFCatalogContentWrapper& src) :
        PFCatalogContentWrapper{ src.Model() }
    {
    }

    PFCatalogContentWrapper(PFCatalogContentWrapper&& src) :
        PFCatalogContentWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogContentWrapper& operator=(PFCatalogContentWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogContentWrapper() = default;

    friend void swap(PFCatalogContentWrapper& lhs, PFCatalogContentWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_maxClientVersion, rhs.m_maxClientVersion);
        swap(lhs.m_minClientVersion, rhs.m_minClientVersion);
        swap(lhs.m_url, rhs.m_url);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetMaxClientVersion(String value)
    {
        m_maxClientVersion = std::move(value);
        this->m_model.maxClientVersion =  m_maxClientVersion.empty() ? nullptr : m_maxClientVersion.data();
    }

    void SetMinClientVersion(String value)
    {
        m_minClientVersion = std::move(value);
        this->m_model.minClientVersion =  m_minClientVersion.empty() ? nullptr : m_minClientVersion.data();
    }

    void SetUrl(String value)
    {
        m_url = std::move(value);
        this->m_model.url =  m_url.empty() ? nullptr : m_url.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.maxClientVersion = m_maxClientVersion.empty() ? nullptr : m_maxClientVersion.data();
        this->m_model.minClientVersion = m_minClientVersion.empty() ? nullptr : m_minClientVersion.data();
        this->m_model.url = m_url.empty() ? nullptr : m_url.data();
    }

    String m_id;
    String m_maxClientVersion;
    String m_minClientVersion;
    String m_url;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogImageWrapper : public ModelWrapper<PFCatalogImage, Alloc>
{
public:
    using ModelType = typename PFCatalogImage;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogImageWrapper() = default;

    PFCatalogImageWrapper(const PFCatalogImage& model) :
        ModelWrapper<PFCatalogImage, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_type{ SafeString(model.type) },
        m_url{ SafeString(model.url) }
    {
        SetModelPointers();
    }

    PFCatalogImageWrapper(const PFCatalogImageWrapper& src) :
        PFCatalogImageWrapper{ src.Model() }
    {
    }

    PFCatalogImageWrapper(PFCatalogImageWrapper&& src) :
        PFCatalogImageWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogImageWrapper& operator=(PFCatalogImageWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogImageWrapper() = default;

    friend void swap(PFCatalogImageWrapper& lhs, PFCatalogImageWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_type, rhs.m_type);
        swap(lhs.m_url, rhs.m_url);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetType(String value)
    {
        m_type = std::move(value);
        this->m_model.type =  m_type.empty() ? nullptr : m_type.data();
    }

    void SetUrl(String value)
    {
        m_url = std::move(value);
        this->m_model.url =  m_url.empty() ? nullptr : m_url.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.type = m_type.empty() ? nullptr : m_type.data();
        this->m_model.url = m_url.empty() ? nullptr : m_url.data();
    }

    String m_id;
    String m_type;
    String m_url;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogKeywordSetWrapper : public ModelWrapper<PFCatalogKeywordSet, Alloc>
{
public:
    using ModelType = typename PFCatalogKeywordSet;
    using DictionaryEntryType = typename PFCatalogKeywordSetDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogKeywordSetWrapper() = default;

    PFCatalogKeywordSetWrapper(const PFCatalogKeywordSet& model) :
        ModelWrapper<PFCatalogKeywordSet, Alloc>{ model },
        m_values{ model.values, model.values + model.valuesCount }
    {
        SetModelPointers();
    }

    PFCatalogKeywordSetWrapper(const PFCatalogKeywordSetWrapper& src) :
        PFCatalogKeywordSetWrapper{ src.Model() }
    {
    }

    PFCatalogKeywordSetWrapper(PFCatalogKeywordSetWrapper&& src) :
        PFCatalogKeywordSetWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogKeywordSetWrapper& operator=(PFCatalogKeywordSetWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogKeywordSetWrapper() = default;

    friend void swap(PFCatalogKeywordSetWrapper& lhs, PFCatalogKeywordSetWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_values, rhs.m_values);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetValues(CStringVector<Alloc> value)
    {
        m_values = std::move(value);
        this->m_model.values =  m_values.empty() ? nullptr : m_values.data();
        this->m_model.valuesCount =  static_cast<uint32_t>(m_values.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.values = m_values.empty() ? nullptr : m_values.data();
    }

    CStringVector<Alloc> m_values;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogModerationStateWrapper : public ModelWrapper<PFCatalogModerationState, Alloc>
{
public:
    using ModelType = typename PFCatalogModerationState;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogModerationStateWrapper() = default;

    PFCatalogModerationStateWrapper(const PFCatalogModerationState& model) :
        ModelWrapper<PFCatalogModerationState, Alloc>{ model },
        m_lastModifiedDate{ model.lastModifiedDate ? StdExtra::optional<time_t>{ *model.lastModifiedDate } : StdExtra::nullopt },
        m_reason{ SafeString(model.reason) },
        m_status{ model.status ? StdExtra::optional<PFCatalogModerationStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogModerationStateWrapper(const PFCatalogModerationStateWrapper& src) :
        PFCatalogModerationStateWrapper{ src.Model() }
    {
    }

    PFCatalogModerationStateWrapper(PFCatalogModerationStateWrapper&& src) :
        PFCatalogModerationStateWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogModerationStateWrapper& operator=(PFCatalogModerationStateWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogModerationStateWrapper() = default;

    friend void swap(PFCatalogModerationStateWrapper& lhs, PFCatalogModerationStateWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lastModifiedDate, rhs.m_lastModifiedDate);
        swap(lhs.m_reason, rhs.m_reason);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLastModifiedDate(StdExtra::optional<time_t> value)
    {
        m_lastModifiedDate = std::move(value);
        this->m_model.lastModifiedDate = m_lastModifiedDate ? m_lastModifiedDate.operator->() : nullptr;
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

    void SetStatus(StdExtra::optional<PFCatalogModerationStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.lastModifiedDate = m_lastModifiedDate ? m_lastModifiedDate.operator->() : nullptr;
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    StdExtra::optional<time_t> m_lastModifiedDate;
    String m_reason;
    StdExtra::optional<PFCatalogModerationStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogRatingWrapper : public ModelWrapper<PFCatalogRating, Alloc>
{
public:
    using ModelType = typename PFCatalogRating;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogRatingWrapper() = default;

    PFCatalogRatingWrapper(const PFCatalogRating& model) :
        ModelWrapper<PFCatalogRating, Alloc>{ model },
        m_average{ model.average ? StdExtra::optional<float>{ *model.average } : StdExtra::nullopt },
        m_count1Star{ model.count1Star ? StdExtra::optional<int32_t>{ *model.count1Star } : StdExtra::nullopt },
        m_count2Star{ model.count2Star ? StdExtra::optional<int32_t>{ *model.count2Star } : StdExtra::nullopt },
        m_count3Star{ model.count3Star ? StdExtra::optional<int32_t>{ *model.count3Star } : StdExtra::nullopt },
        m_count4Star{ model.count4Star ? StdExtra::optional<int32_t>{ *model.count4Star } : StdExtra::nullopt },
        m_count5Star{ model.count5Star ? StdExtra::optional<int32_t>{ *model.count5Star } : StdExtra::nullopt },
        m_totalCount{ model.totalCount ? StdExtra::optional<int32_t>{ *model.totalCount } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogRatingWrapper(const PFCatalogRatingWrapper& src) :
        PFCatalogRatingWrapper{ src.Model() }
    {
    }

    PFCatalogRatingWrapper(PFCatalogRatingWrapper&& src) :
        PFCatalogRatingWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogRatingWrapper& operator=(PFCatalogRatingWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogRatingWrapper() = default;

    friend void swap(PFCatalogRatingWrapper& lhs, PFCatalogRatingWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_average, rhs.m_average);
        swap(lhs.m_count1Star, rhs.m_count1Star);
        swap(lhs.m_count2Star, rhs.m_count2Star);
        swap(lhs.m_count3Star, rhs.m_count3Star);
        swap(lhs.m_count4Star, rhs.m_count4Star);
        swap(lhs.m_count5Star, rhs.m_count5Star);
        swap(lhs.m_totalCount, rhs.m_totalCount);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAverage(StdExtra::optional<float> value)
    {
        m_average = std::move(value);
        this->m_model.average = m_average ? m_average.operator->() : nullptr;
    }

    void SetCount1Star(StdExtra::optional<int32_t> value)
    {
        m_count1Star = std::move(value);
        this->m_model.count1Star = m_count1Star ? m_count1Star.operator->() : nullptr;
    }

    void SetCount2Star(StdExtra::optional<int32_t> value)
    {
        m_count2Star = std::move(value);
        this->m_model.count2Star = m_count2Star ? m_count2Star.operator->() : nullptr;
    }

    void SetCount3Star(StdExtra::optional<int32_t> value)
    {
        m_count3Star = std::move(value);
        this->m_model.count3Star = m_count3Star ? m_count3Star.operator->() : nullptr;
    }

    void SetCount4Star(StdExtra::optional<int32_t> value)
    {
        m_count4Star = std::move(value);
        this->m_model.count4Star = m_count4Star ? m_count4Star.operator->() : nullptr;
    }

    void SetCount5Star(StdExtra::optional<int32_t> value)
    {
        m_count5Star = std::move(value);
        this->m_model.count5Star = m_count5Star ? m_count5Star.operator->() : nullptr;
    }

    void SetTotalCount(StdExtra::optional<int32_t> value)
    {
        m_totalCount = std::move(value);
        this->m_model.totalCount = m_totalCount ? m_totalCount.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.average = m_average ? m_average.operator->() : nullptr;
        this->m_model.count1Star = m_count1Star ? m_count1Star.operator->() : nullptr;
        this->m_model.count2Star = m_count2Star ? m_count2Star.operator->() : nullptr;
        this->m_model.count3Star = m_count3Star ? m_count3Star.operator->() : nullptr;
        this->m_model.count4Star = m_count4Star ? m_count4Star.operator->() : nullptr;
        this->m_model.count5Star = m_count5Star ? m_count5Star.operator->() : nullptr;
        this->m_model.totalCount = m_totalCount ? m_totalCount.operator->() : nullptr;
    }

    StdExtra::optional<float> m_average;
    StdExtra::optional<int32_t> m_count1Star;
    StdExtra::optional<int32_t> m_count2Star;
    StdExtra::optional<int32_t> m_count3Star;
    StdExtra::optional<int32_t> m_count4Star;
    StdExtra::optional<int32_t> m_count5Star;
    StdExtra::optional<int32_t> m_totalCount;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCatalogItemWrapper : public ModelWrapper<PFCatalogCatalogItem, Alloc>
{
public:
    using ModelType = typename PFCatalogCatalogItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCatalogItemWrapper() = default;

    PFCatalogCatalogItemWrapper(const PFCatalogCatalogItem& model) :
        ModelWrapper<PFCatalogCatalogItem, Alloc>{ model },
        m_alternateIds{ model.alternateIds, model.alternateIds + model.alternateIdsCount },
        m_contents{ model.contents, model.contents + model.contentsCount },
        m_contentType{ SafeString(model.contentType) },
        m_creationDate{ model.creationDate ? StdExtra::optional<time_t>{ *model.creationDate } : StdExtra::nullopt },
        m_creatorEntity{ model.creatorEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.creatorEntity } : StdExtra::nullopt },
        m_description{ model.description, model.description + model.descriptionCount },
        m_displayProperties{ model.displayProperties },
        m_displayVersion{ SafeString(model.displayVersion) },
        m_endDate{ model.endDate ? StdExtra::optional<time_t>{ *model.endDate } : StdExtra::nullopt },
        m_eTag{ SafeString(model.eTag) },
        m_id{ SafeString(model.id) },
        m_images{ model.images, model.images + model.imagesCount },
        m_isHidden{ model.isHidden ? StdExtra::optional<bool>{ *model.isHidden } : StdExtra::nullopt },
        m_keywords{ model.keywords, model.keywords + model.keywordsCount },
        m_lastModifiedDate{ model.lastModifiedDate ? StdExtra::optional<time_t>{ *model.lastModifiedDate } : StdExtra::nullopt },
        m_moderation{ model.moderation ? StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>>{ *model.moderation } : StdExtra::nullopt },
        m_rating{ model.rating ? StdExtra::optional<PFCatalogRatingWrapper<Alloc>>{ *model.rating } : StdExtra::nullopt },
        m_startDate{ model.startDate ? StdExtra::optional<time_t>{ *model.startDate } : StdExtra::nullopt },
        m_tags{ model.tags, model.tags + model.tagsCount },
        m_title{ model.title, model.title + model.titleCount },
        m_type{ SafeString(model.type) }
    {
        SetModelPointers();
    }

    PFCatalogCatalogItemWrapper(const PFCatalogCatalogItemWrapper& src) :
        PFCatalogCatalogItemWrapper{ src.Model() }
    {
    }

    PFCatalogCatalogItemWrapper(PFCatalogCatalogItemWrapper&& src) :
        PFCatalogCatalogItemWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCatalogItemWrapper& operator=(PFCatalogCatalogItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCatalogItemWrapper() = default;

    friend void swap(PFCatalogCatalogItemWrapper& lhs, PFCatalogCatalogItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateIds, rhs.m_alternateIds);
        swap(lhs.m_contents, rhs.m_contents);
        swap(lhs.m_contentType, rhs.m_contentType);
        swap(lhs.m_creationDate, rhs.m_creationDate);
        swap(lhs.m_creatorEntity, rhs.m_creatorEntity);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_displayProperties, rhs.m_displayProperties);
        swap(lhs.m_displayVersion, rhs.m_displayVersion);
        swap(lhs.m_endDate, rhs.m_endDate);
        swap(lhs.m_eTag, rhs.m_eTag);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_images, rhs.m_images);
        swap(lhs.m_isHidden, rhs.m_isHidden);
        swap(lhs.m_keywords, rhs.m_keywords);
        swap(lhs.m_lastModifiedDate, rhs.m_lastModifiedDate);
        swap(lhs.m_moderation, rhs.m_moderation);
        swap(lhs.m_rating, rhs.m_rating);
        swap(lhs.m_startDate, rhs.m_startDate);
        swap(lhs.m_tags, rhs.m_tags);
        swap(lhs.m_title, rhs.m_title);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateIds(ModelVector<PFCatalogCatalogAlternateIdWrapper<Alloc>, Alloc> value)
    {
        m_alternateIds = std::move(value);
        this->m_model.alternateIds =  m_alternateIds.empty() ? nullptr : m_alternateIds.data();
        this->m_model.alternateIdsCount =  static_cast<uint32_t>(m_alternateIds.size());
    }

    void SetContents(ModelVector<PFCatalogContentWrapper<Alloc>, Alloc> value)
    {
        m_contents = std::move(value);
        this->m_model.contents =  m_contents.empty() ? nullptr : m_contents.data();
        this->m_model.contentsCount =  static_cast<uint32_t>(m_contents.size());
    }

    void SetContentType(String value)
    {
        m_contentType = std::move(value);
        this->m_model.contentType =  m_contentType.empty() ? nullptr : m_contentType.data();
    }

    void SetCreationDate(StdExtra::optional<time_t> value)
    {
        m_creationDate = std::move(value);
        this->m_model.creationDate = m_creationDate ? m_creationDate.operator->() : nullptr;
    }

    void SetCreatorEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_creatorEntity = std::move(value);
        this->m_model.creatorEntity = m_creatorEntity ? &m_creatorEntity->Model() : nullptr;
    }

    void SetDescription(StringDictionaryEntryVector<Alloc> value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
        this->m_model.descriptionCount =  static_cast<uint32_t>(m_description.size());
    }

    void SetDisplayProperties(JsonObject<Alloc> value)
    {
        m_displayProperties = std::move(value);
        this->m_model.displayProperties.stringValue = m_displayProperties.stringValue.empty() ? nullptr : m_displayProperties.stringValue.data();
    }

    void SetDisplayVersion(String value)
    {
        m_displayVersion = std::move(value);
        this->m_model.displayVersion =  m_displayVersion.empty() ? nullptr : m_displayVersion.data();
    }

    void SetEndDate(StdExtra::optional<time_t> value)
    {
        m_endDate = std::move(value);
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
    }

    void SetETag(String value)
    {
        m_eTag = std::move(value);
        this->m_model.eTag =  m_eTag.empty() ? nullptr : m_eTag.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetImages(ModelVector<PFCatalogImageWrapper<Alloc>, Alloc> value)
    {
        m_images = std::move(value);
        this->m_model.images =  m_images.empty() ? nullptr : m_images.data();
        this->m_model.imagesCount =  static_cast<uint32_t>(m_images.size());
    }

    void SetIsHidden(StdExtra::optional<bool> value)
    {
        m_isHidden = std::move(value);
        this->m_model.isHidden = m_isHidden ? m_isHidden.operator->() : nullptr;
    }

    void SetKeywords(ModelDictionaryEntryVector<PFCatalogKeywordSetWrapper<Alloc>, Alloc> value)
    {
        m_keywords = std::move(value);
        this->m_model.keywords =  m_keywords.empty() ? nullptr : m_keywords.data();
        this->m_model.keywordsCount =  static_cast<uint32_t>(m_keywords.size());
    }

    void SetLastModifiedDate(StdExtra::optional<time_t> value)
    {
        m_lastModifiedDate = std::move(value);
        this->m_model.lastModifiedDate = m_lastModifiedDate ? m_lastModifiedDate.operator->() : nullptr;
    }

    void SetModeration(StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>> value)
    {
        m_moderation = std::move(value);
        this->m_model.moderation = m_moderation ? &m_moderation->Model() : nullptr;
    }

    void SetRating(StdExtra::optional<PFCatalogRatingWrapper<Alloc>> value)
    {
        m_rating = std::move(value);
        this->m_model.rating = m_rating ? &m_rating->Model() : nullptr;
    }

    void SetStartDate(StdExtra::optional<time_t> value)
    {
        m_startDate = std::move(value);
        this->m_model.startDate = m_startDate ? m_startDate.operator->() : nullptr;
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

    void SetTitle(StringDictionaryEntryVector<Alloc> value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
        this->m_model.titleCount =  static_cast<uint32_t>(m_title.size());
    }

    void SetType(String value)
    {
        m_type = std::move(value);
        this->m_model.type =  m_type.empty() ? nullptr : m_type.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateIds = m_alternateIds.empty() ? nullptr : m_alternateIds.data();
        this->m_model.contents = m_contents.empty() ? nullptr : m_contents.data();
        this->m_model.contentType = m_contentType.empty() ? nullptr : m_contentType.data();
        this->m_model.creationDate = m_creationDate ? m_creationDate.operator->() : nullptr;
        this->m_model.creatorEntity = m_creatorEntity ?  &m_creatorEntity->Model() : nullptr;
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.displayProperties.stringValue = m_displayProperties.stringValue.empty() ? nullptr : m_displayProperties.stringValue.data();
        this->m_model.displayVersion = m_displayVersion.empty() ? nullptr : m_displayVersion.data();
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
        this->m_model.eTag = m_eTag.empty() ? nullptr : m_eTag.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.images = m_images.empty() ? nullptr : m_images.data();
        this->m_model.isHidden = m_isHidden ? m_isHidden.operator->() : nullptr;
        this->m_model.keywords = m_keywords.empty() ? nullptr : m_keywords.data();
        this->m_model.lastModifiedDate = m_lastModifiedDate ? m_lastModifiedDate.operator->() : nullptr;
        this->m_model.moderation = m_moderation ?  &m_moderation->Model() : nullptr;
        this->m_model.rating = m_rating ?  &m_rating->Model() : nullptr;
        this->m_model.startDate = m_startDate ? m_startDate.operator->() : nullptr;
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
        this->m_model.type = m_type.empty() ? nullptr : m_type.data();
    }

    ModelVector<PFCatalogCatalogAlternateIdWrapper<Alloc>, Alloc> m_alternateIds;
    ModelVector<PFCatalogContentWrapper<Alloc>, Alloc> m_contents;
    String m_contentType;
    StdExtra::optional<time_t> m_creationDate;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_creatorEntity;
    StringDictionaryEntryVector<Alloc> m_description;
    JsonObject<Alloc> m_displayProperties;
    String m_displayVersion;
    StdExtra::optional<time_t> m_endDate;
    String m_eTag;
    String m_id;
    ModelVector<PFCatalogImageWrapper<Alloc>, Alloc> m_images;
    StdExtra::optional<bool> m_isHidden;
    ModelDictionaryEntryVector<PFCatalogKeywordSetWrapper<Alloc>, Alloc> m_keywords;
    StdExtra::optional<time_t> m_lastModifiedDate;
    StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>> m_moderation;
    StdExtra::optional<PFCatalogRatingWrapper<Alloc>> m_rating;
    StdExtra::optional<time_t> m_startDate;
    CStringVector<Alloc> m_tags;
    StringDictionaryEntryVector<Alloc> m_title;
    String m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCreateDraftItemRequestWrapper : public ModelWrapper<PFCatalogCreateDraftItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogCreateDraftItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCreateDraftItemRequestWrapper() = default;

    PFCatalogCreateDraftItemRequestWrapper(const PFCatalogCreateDraftItemRequest& model) :
        ModelWrapper<PFCatalogCreateDraftItemRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogCreateDraftItemRequestWrapper(const PFCatalogCreateDraftItemRequestWrapper& src) :
        PFCatalogCreateDraftItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogCreateDraftItemRequestWrapper(PFCatalogCreateDraftItemRequestWrapper&& src) :
        PFCatalogCreateDraftItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCreateDraftItemRequestWrapper& operator=(PFCatalogCreateDraftItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCreateDraftItemRequestWrapper() = default;

    friend void swap(PFCatalogCreateDraftItemRequestWrapper& lhs, PFCatalogCreateDraftItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

    void SetPublish(bool value)
    {
        this->m_model.publish = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCreateDraftItemResponseWrapper : public ModelWrapper<PFCatalogCreateDraftItemResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogCreateDraftItemResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCreateDraftItemResponseWrapper() = default;

    PFCatalogCreateDraftItemResponseWrapper(const PFCatalogCreateDraftItemResponse& model) :
        ModelWrapper<PFCatalogCreateDraftItemResponse, Alloc>{ model },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogCreateDraftItemResponseWrapper(const PFCatalogCreateDraftItemResponseWrapper& src) :
        PFCatalogCreateDraftItemResponseWrapper{ src.Model() }
    {
    }

    PFCatalogCreateDraftItemResponseWrapper(PFCatalogCreateDraftItemResponseWrapper&& src) :
        PFCatalogCreateDraftItemResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCreateDraftItemResponseWrapper& operator=(PFCatalogCreateDraftItemResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCreateDraftItemResponseWrapper() = default;

    friend void swap(PFCatalogCreateDraftItemResponseWrapper& lhs, PFCatalogCreateDraftItemResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUploadInfoWrapper : public ModelWrapper<PFCatalogUploadInfo, Alloc>
{
public:
    using ModelType = typename PFCatalogUploadInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUploadInfoWrapper() = default;

    PFCatalogUploadInfoWrapper(const PFCatalogUploadInfo& model) :
        ModelWrapper<PFCatalogUploadInfo, Alloc>{ model },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFCatalogUploadInfoWrapper(const PFCatalogUploadInfoWrapper& src) :
        PFCatalogUploadInfoWrapper{ src.Model() }
    {
    }

    PFCatalogUploadInfoWrapper(PFCatalogUploadInfoWrapper&& src) :
        PFCatalogUploadInfoWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUploadInfoWrapper& operator=(PFCatalogUploadInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUploadInfoWrapper() = default;

    friend void swap(PFCatalogUploadInfoWrapper& lhs, PFCatalogUploadInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCreateUploadUrlsRequestWrapper : public ModelWrapper<PFCatalogCreateUploadUrlsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogCreateUploadUrlsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCreateUploadUrlsRequestWrapper() = default;

    PFCatalogCreateUploadUrlsRequestWrapper(const PFCatalogCreateUploadUrlsRequest& model) :
        ModelWrapper<PFCatalogCreateUploadUrlsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_files{ model.files, model.files + model.filesCount }
    {
        SetModelPointers();
    }

    PFCatalogCreateUploadUrlsRequestWrapper(const PFCatalogCreateUploadUrlsRequestWrapper& src) :
        PFCatalogCreateUploadUrlsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogCreateUploadUrlsRequestWrapper(PFCatalogCreateUploadUrlsRequestWrapper&& src) :
        PFCatalogCreateUploadUrlsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCreateUploadUrlsRequestWrapper& operator=(PFCatalogCreateUploadUrlsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCreateUploadUrlsRequestWrapper() = default;

    friend void swap(PFCatalogCreateUploadUrlsRequestWrapper& lhs, PFCatalogCreateUploadUrlsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_files, rhs.m_files);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFiles(ModelVector<PFCatalogUploadInfoWrapper<Alloc>, Alloc> value)
    {
        m_files = std::move(value);
        this->m_model.files =  m_files.empty() ? nullptr : m_files.data();
        this->m_model.filesCount =  static_cast<uint32_t>(m_files.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.files = m_files.empty() ? nullptr : m_files.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFCatalogUploadInfoWrapper<Alloc>, Alloc> m_files;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUploadUrlMetadataWrapper : public ModelWrapper<PFCatalogUploadUrlMetadata, Alloc>
{
public:
    using ModelType = typename PFCatalogUploadUrlMetadata;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUploadUrlMetadataWrapper() = default;

    PFCatalogUploadUrlMetadataWrapper(const PFCatalogUploadUrlMetadata& model) :
        ModelWrapper<PFCatalogUploadUrlMetadata, Alloc>{ model },
        m_fileName{ SafeString(model.fileName) },
        m_id{ SafeString(model.id) },
        m_url{ SafeString(model.url) }
    {
        SetModelPointers();
    }

    PFCatalogUploadUrlMetadataWrapper(const PFCatalogUploadUrlMetadataWrapper& src) :
        PFCatalogUploadUrlMetadataWrapper{ src.Model() }
    {
    }

    PFCatalogUploadUrlMetadataWrapper(PFCatalogUploadUrlMetadataWrapper&& src) :
        PFCatalogUploadUrlMetadataWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUploadUrlMetadataWrapper& operator=(PFCatalogUploadUrlMetadataWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUploadUrlMetadataWrapper() = default;

    friend void swap(PFCatalogUploadUrlMetadataWrapper& lhs, PFCatalogUploadUrlMetadataWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileName, rhs.m_fileName);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_url, rhs.m_url);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetUrl(String value)
    {
        m_url = std::move(value);
        this->m_model.url =  m_url.empty() ? nullptr : m_url.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.url = m_url.empty() ? nullptr : m_url.data();
    }

    String m_fileName;
    String m_id;
    String m_url;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCreateUploadUrlsResponseWrapper : public ModelWrapper<PFCatalogCreateUploadUrlsResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogCreateUploadUrlsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCreateUploadUrlsResponseWrapper() = default;

    PFCatalogCreateUploadUrlsResponseWrapper(const PFCatalogCreateUploadUrlsResponse& model) :
        ModelWrapper<PFCatalogCreateUploadUrlsResponse, Alloc>{ model },
        m_uploadUrls{ model.uploadUrls, model.uploadUrls + model.uploadUrlsCount }
    {
        SetModelPointers();
    }

    PFCatalogCreateUploadUrlsResponseWrapper(const PFCatalogCreateUploadUrlsResponseWrapper& src) :
        PFCatalogCreateUploadUrlsResponseWrapper{ src.Model() }
    {
    }

    PFCatalogCreateUploadUrlsResponseWrapper(PFCatalogCreateUploadUrlsResponseWrapper&& src) :
        PFCatalogCreateUploadUrlsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCreateUploadUrlsResponseWrapper& operator=(PFCatalogCreateUploadUrlsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCreateUploadUrlsResponseWrapper() = default;

    friend void swap(PFCatalogCreateUploadUrlsResponseWrapper& lhs, PFCatalogCreateUploadUrlsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_uploadUrls, rhs.m_uploadUrls);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUploadUrls(ModelVector<PFCatalogUploadUrlMetadataWrapper<Alloc>, Alloc> value)
    {
        m_uploadUrls = std::move(value);
        this->m_model.uploadUrls =  m_uploadUrls.empty() ? nullptr : m_uploadUrls.data();
        this->m_model.uploadUrlsCount =  static_cast<uint32_t>(m_uploadUrls.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.uploadUrls = m_uploadUrls.empty() ? nullptr : m_uploadUrls.data();
    }

    ModelVector<PFCatalogUploadUrlMetadataWrapper<Alloc>, Alloc> m_uploadUrls;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogDeleteEntityItemReviewsRequestWrapper : public ModelWrapper<PFCatalogDeleteEntityItemReviewsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogDeleteEntityItemReviewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogDeleteEntityItemReviewsRequestWrapper() = default;

    PFCatalogDeleteEntityItemReviewsRequestWrapper(const PFCatalogDeleteEntityItemReviewsRequest& model) :
        ModelWrapper<PFCatalogDeleteEntityItemReviewsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogDeleteEntityItemReviewsRequestWrapper(const PFCatalogDeleteEntityItemReviewsRequestWrapper& src) :
        PFCatalogDeleteEntityItemReviewsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogDeleteEntityItemReviewsRequestWrapper(PFCatalogDeleteEntityItemReviewsRequestWrapper&& src) :
        PFCatalogDeleteEntityItemReviewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogDeleteEntityItemReviewsRequestWrapper& operator=(PFCatalogDeleteEntityItemReviewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogDeleteEntityItemReviewsRequestWrapper() = default;

    friend void swap(PFCatalogDeleteEntityItemReviewsRequestWrapper& lhs, PFCatalogDeleteEntityItemReviewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogDeleteItemRequestWrapper : public ModelWrapper<PFCatalogDeleteItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogDeleteItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogDeleteItemRequestWrapper() = default;

    PFCatalogDeleteItemRequestWrapper(const PFCatalogDeleteItemRequest& model) :
        ModelWrapper<PFCatalogDeleteItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogDeleteItemRequestWrapper(const PFCatalogDeleteItemRequestWrapper& src) :
        PFCatalogDeleteItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogDeleteItemRequestWrapper(PFCatalogDeleteItemRequestWrapper&& src) :
        PFCatalogDeleteItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogDeleteItemRequestWrapper& operator=(PFCatalogDeleteItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogDeleteItemRequestWrapper() = default;

    friend void swap(PFCatalogDeleteItemRequestWrapper& lhs, PFCatalogDeleteItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetCatalogConfigRequestWrapper : public ModelWrapper<PFCatalogGetCatalogConfigRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetCatalogConfigRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetCatalogConfigRequestWrapper() = default;

    PFCatalogGetCatalogConfigRequestWrapper(const PFCatalogGetCatalogConfigRequest& model) :
        ModelWrapper<PFCatalogGetCatalogConfigRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFCatalogGetCatalogConfigRequestWrapper(const PFCatalogGetCatalogConfigRequestWrapper& src) :
        PFCatalogGetCatalogConfigRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetCatalogConfigRequestWrapper(PFCatalogGetCatalogConfigRequestWrapper&& src) :
        PFCatalogGetCatalogConfigRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetCatalogConfigRequestWrapper& operator=(PFCatalogGetCatalogConfigRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetCatalogConfigRequestWrapper() = default;

    friend void swap(PFCatalogGetCatalogConfigRequestWrapper& lhs, PFCatalogGetCatalogConfigRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogDisplayPropertyIndexInfoWrapper : public ModelWrapper<PFCatalogDisplayPropertyIndexInfo, Alloc>
{
public:
    using ModelType = typename PFCatalogDisplayPropertyIndexInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogDisplayPropertyIndexInfoWrapper() = default;

    PFCatalogDisplayPropertyIndexInfoWrapper(const PFCatalogDisplayPropertyIndexInfo& model) :
        ModelWrapper<PFCatalogDisplayPropertyIndexInfo, Alloc>{ model },
        m_name{ SafeString(model.name) },
        m_type{ model.type ? StdExtra::optional<PFCatalogDisplayPropertyType>{ *model.type } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogDisplayPropertyIndexInfoWrapper(const PFCatalogDisplayPropertyIndexInfoWrapper& src) :
        PFCatalogDisplayPropertyIndexInfoWrapper{ src.Model() }
    {
    }

    PFCatalogDisplayPropertyIndexInfoWrapper(PFCatalogDisplayPropertyIndexInfoWrapper&& src) :
        PFCatalogDisplayPropertyIndexInfoWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogDisplayPropertyIndexInfoWrapper& operator=(PFCatalogDisplayPropertyIndexInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogDisplayPropertyIndexInfoWrapper() = default;

    friend void swap(PFCatalogDisplayPropertyIndexInfoWrapper& lhs, PFCatalogDisplayPropertyIndexInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetType(StdExtra::optional<PFCatalogDisplayPropertyType> value)
    {
        m_type = std::move(value);
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

    String m_name;
    StdExtra::optional<PFCatalogDisplayPropertyType> m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUserGeneratedContentSpecificConfigWrapper : public ModelWrapper<PFCatalogUserGeneratedContentSpecificConfig, Alloc>
{
public:
    using ModelType = typename PFCatalogUserGeneratedContentSpecificConfig;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUserGeneratedContentSpecificConfigWrapper() = default;

    PFCatalogUserGeneratedContentSpecificConfigWrapper(const PFCatalogUserGeneratedContentSpecificConfig& model) :
        ModelWrapper<PFCatalogUserGeneratedContentSpecificConfig, Alloc>{ model },
        m_contentTypes{ model.contentTypes, model.contentTypes + model.contentTypesCount },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFCatalogUserGeneratedContentSpecificConfigWrapper(const PFCatalogUserGeneratedContentSpecificConfigWrapper& src) :
        PFCatalogUserGeneratedContentSpecificConfigWrapper{ src.Model() }
    {
    }

    PFCatalogUserGeneratedContentSpecificConfigWrapper(PFCatalogUserGeneratedContentSpecificConfigWrapper&& src) :
        PFCatalogUserGeneratedContentSpecificConfigWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUserGeneratedContentSpecificConfigWrapper& operator=(PFCatalogUserGeneratedContentSpecificConfigWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUserGeneratedContentSpecificConfigWrapper() = default;

    friend void swap(PFCatalogUserGeneratedContentSpecificConfigWrapper& lhs, PFCatalogUserGeneratedContentSpecificConfigWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_contentTypes, rhs.m_contentTypes);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContentTypes(CStringVector<Alloc> value)
    {
        m_contentTypes = std::move(value);
        this->m_model.contentTypes =  m_contentTypes.empty() ? nullptr : m_contentTypes.data();
        this->m_model.contentTypesCount =  static_cast<uint32_t>(m_contentTypes.size());
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.contentTypes = m_contentTypes.empty() ? nullptr : m_contentTypes.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    CStringVector<Alloc> m_contentTypes;
    CStringVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogCatalogConfigWrapper : public ModelWrapper<PFCatalogCatalogConfig, Alloc>
{
public:
    using ModelType = typename PFCatalogCatalogConfig;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogCatalogConfigWrapper() = default;

    PFCatalogCatalogConfigWrapper(const PFCatalogCatalogConfig& model) :
        ModelWrapper<PFCatalogCatalogConfig, Alloc>{ model },
        m_adminEntities{ model.adminEntities, model.adminEntities + model.adminEntitiesCount },
        m_displayPropertyIndexInfos{ model.displayPropertyIndexInfos, model.displayPropertyIndexInfos + model.displayPropertyIndexInfosCount },
        m_reviewerEntities{ model.reviewerEntities, model.reviewerEntities + model.reviewerEntitiesCount },
        m_userGeneratedContent{ model.userGeneratedContent ? StdExtra::optional<PFCatalogUserGeneratedContentSpecificConfigWrapper<Alloc>>{ *model.userGeneratedContent } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogCatalogConfigWrapper(const PFCatalogCatalogConfigWrapper& src) :
        PFCatalogCatalogConfigWrapper{ src.Model() }
    {
    }

    PFCatalogCatalogConfigWrapper(PFCatalogCatalogConfigWrapper&& src) :
        PFCatalogCatalogConfigWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogCatalogConfigWrapper& operator=(PFCatalogCatalogConfigWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogCatalogConfigWrapper() = default;

    friend void swap(PFCatalogCatalogConfigWrapper& lhs, PFCatalogCatalogConfigWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adminEntities, rhs.m_adminEntities);
        swap(lhs.m_displayPropertyIndexInfos, rhs.m_displayPropertyIndexInfos);
        swap(lhs.m_reviewerEntities, rhs.m_reviewerEntities);
        swap(lhs.m_userGeneratedContent, rhs.m_userGeneratedContent);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdminEntities(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_adminEntities = std::move(value);
        this->m_model.adminEntities =  m_adminEntities.empty() ? nullptr : m_adminEntities.data();
        this->m_model.adminEntitiesCount =  static_cast<uint32_t>(m_adminEntities.size());
    }

    void SetDisplayPropertyIndexInfos(ModelVector<PFCatalogDisplayPropertyIndexInfoWrapper<Alloc>, Alloc> value)
    {
        m_displayPropertyIndexInfos = std::move(value);
        this->m_model.displayPropertyIndexInfos =  m_displayPropertyIndexInfos.empty() ? nullptr : m_displayPropertyIndexInfos.data();
        this->m_model.displayPropertyIndexInfosCount =  static_cast<uint32_t>(m_displayPropertyIndexInfos.size());
    }

    void SetIsCatalogEnabled(bool value)
    {
        this->m_model.isCatalogEnabled = value;
    }

    void SetReviewerEntities(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_reviewerEntities = std::move(value);
        this->m_model.reviewerEntities =  m_reviewerEntities.empty() ? nullptr : m_reviewerEntities.data();
        this->m_model.reviewerEntitiesCount =  static_cast<uint32_t>(m_reviewerEntities.size());
    }

    void SetUserGeneratedContent(StdExtra::optional<PFCatalogUserGeneratedContentSpecificConfigWrapper<Alloc>> value)
    {
        m_userGeneratedContent = std::move(value);
        this->m_model.userGeneratedContent = m_userGeneratedContent ? &m_userGeneratedContent->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.adminEntities = m_adminEntities.empty() ? nullptr : m_adminEntities.data();
        this->m_model.displayPropertyIndexInfos = m_displayPropertyIndexInfos.empty() ? nullptr : m_displayPropertyIndexInfos.data();
        this->m_model.reviewerEntities = m_reviewerEntities.empty() ? nullptr : m_reviewerEntities.data();
        this->m_model.userGeneratedContent = m_userGeneratedContent ?  &m_userGeneratedContent->Model() : nullptr;
    }

    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_adminEntities;
    ModelVector<PFCatalogDisplayPropertyIndexInfoWrapper<Alloc>, Alloc> m_displayPropertyIndexInfos;
    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_reviewerEntities;
    StdExtra::optional<PFCatalogUserGeneratedContentSpecificConfigWrapper<Alloc>> m_userGeneratedContent;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetCatalogConfigResponseWrapper : public ModelWrapper<PFCatalogGetCatalogConfigResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetCatalogConfigResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetCatalogConfigResponseWrapper() = default;

    PFCatalogGetCatalogConfigResponseWrapper(const PFCatalogGetCatalogConfigResponse& model) :
        ModelWrapper<PFCatalogGetCatalogConfigResponse, Alloc>{ model },
        m_config{ model.config ? StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>>{ *model.config } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetCatalogConfigResponseWrapper(const PFCatalogGetCatalogConfigResponseWrapper& src) :
        PFCatalogGetCatalogConfigResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetCatalogConfigResponseWrapper(PFCatalogGetCatalogConfigResponseWrapper&& src) :
        PFCatalogGetCatalogConfigResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetCatalogConfigResponseWrapper& operator=(PFCatalogGetCatalogConfigResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetCatalogConfigResponseWrapper() = default;

    friend void swap(PFCatalogGetCatalogConfigResponseWrapper& lhs, PFCatalogGetCatalogConfigResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_config, rhs.m_config);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConfig(StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>> value)
    {
        m_config = std::move(value);
        this->m_model.config = m_config ? &m_config->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.config = m_config ?  &m_config->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>> m_config;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetDraftItemRequestWrapper : public ModelWrapper<PFCatalogGetDraftItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetDraftItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetDraftItemRequestWrapper() = default;

    PFCatalogGetDraftItemRequestWrapper(const PFCatalogGetDraftItemRequest& model) :
        ModelWrapper<PFCatalogGetDraftItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetDraftItemRequestWrapper(const PFCatalogGetDraftItemRequestWrapper& src) :
        PFCatalogGetDraftItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetDraftItemRequestWrapper(PFCatalogGetDraftItemRequestWrapper&& src) :
        PFCatalogGetDraftItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetDraftItemRequestWrapper& operator=(PFCatalogGetDraftItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetDraftItemRequestWrapper() = default;

    friend void swap(PFCatalogGetDraftItemRequestWrapper& lhs, PFCatalogGetDraftItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetDraftItemResponseWrapper : public ModelWrapper<PFCatalogGetDraftItemResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetDraftItemResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetDraftItemResponseWrapper() = default;

    PFCatalogGetDraftItemResponseWrapper(const PFCatalogGetDraftItemResponse& model) :
        ModelWrapper<PFCatalogGetDraftItemResponse, Alloc>{ model },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetDraftItemResponseWrapper(const PFCatalogGetDraftItemResponseWrapper& src) :
        PFCatalogGetDraftItemResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetDraftItemResponseWrapper(PFCatalogGetDraftItemResponseWrapper&& src) :
        PFCatalogGetDraftItemResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetDraftItemResponseWrapper& operator=(PFCatalogGetDraftItemResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetDraftItemResponseWrapper() = default;

    friend void swap(PFCatalogGetDraftItemResponseWrapper& lhs, PFCatalogGetDraftItemResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetDraftItemsRequestWrapper : public ModelWrapper<PFCatalogGetDraftItemsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetDraftItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetDraftItemsRequestWrapper() = default;

    PFCatalogGetDraftItemsRequestWrapper(const PFCatalogGetDraftItemsRequest& model) :
        ModelWrapper<PFCatalogGetDraftItemsRequest, Alloc>{ model },
        m_alternateIds{ model.alternateIds, model.alternateIds + model.alternateIdsCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_ids{ model.ids, model.ids + model.idsCount }
    {
        SetModelPointers();
    }

    PFCatalogGetDraftItemsRequestWrapper(const PFCatalogGetDraftItemsRequestWrapper& src) :
        PFCatalogGetDraftItemsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetDraftItemsRequestWrapper(PFCatalogGetDraftItemsRequestWrapper&& src) :
        PFCatalogGetDraftItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetDraftItemsRequestWrapper& operator=(PFCatalogGetDraftItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetDraftItemsRequestWrapper() = default;

    friend void swap(PFCatalogGetDraftItemsRequestWrapper& lhs, PFCatalogGetDraftItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateIds, rhs.m_alternateIds);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_ids, rhs.m_ids);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateIds(ModelVector<PFCatalogCatalogAlternateIdWrapper<Alloc>, Alloc> value)
    {
        m_alternateIds = std::move(value);
        this->m_model.alternateIds =  m_alternateIds.empty() ? nullptr : m_alternateIds.data();
        this->m_model.alternateIdsCount =  static_cast<uint32_t>(m_alternateIds.size());
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetIds(CStringVector<Alloc> value)
    {
        m_ids = std::move(value);
        this->m_model.ids =  m_ids.empty() ? nullptr : m_ids.data();
        this->m_model.idsCount =  static_cast<uint32_t>(m_ids.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateIds = m_alternateIds.empty() ? nullptr : m_alternateIds.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.ids = m_ids.empty() ? nullptr : m_ids.data();
    }

    ModelVector<PFCatalogCatalogAlternateIdWrapper<Alloc>, Alloc> m_alternateIds;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    CStringVector<Alloc> m_ids;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetDraftItemsResponseWrapper : public ModelWrapper<PFCatalogGetDraftItemsResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetDraftItemsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetDraftItemsResponseWrapper() = default;

    PFCatalogGetDraftItemsResponseWrapper(const PFCatalogGetDraftItemsResponse& model) :
        ModelWrapper<PFCatalogGetDraftItemsResponse, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFCatalogGetDraftItemsResponseWrapper(const PFCatalogGetDraftItemsResponseWrapper& src) :
        PFCatalogGetDraftItemsResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetDraftItemsResponseWrapper(PFCatalogGetDraftItemsResponseWrapper&& src) :
        PFCatalogGetDraftItemsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetDraftItemsResponseWrapper& operator=(PFCatalogGetDraftItemsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetDraftItemsResponseWrapper() = default;

    friend void swap(PFCatalogGetDraftItemsResponseWrapper& lhs, PFCatalogGetDraftItemsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetItems(ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    String m_continuationToken;
    ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetEntityDraftItemsRequestWrapper : public ModelWrapper<PFCatalogGetEntityDraftItemsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetEntityDraftItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetEntityDraftItemsRequestWrapper() = default;

    PFCatalogGetEntityDraftItemsRequestWrapper(const PFCatalogGetEntityDraftItemsRequest& model) :
        ModelWrapper<PFCatalogGetEntityDraftItemsRequest, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetEntityDraftItemsRequestWrapper(const PFCatalogGetEntityDraftItemsRequestWrapper& src) :
        PFCatalogGetEntityDraftItemsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetEntityDraftItemsRequestWrapper(PFCatalogGetEntityDraftItemsRequestWrapper&& src) :
        PFCatalogGetEntityDraftItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetEntityDraftItemsRequestWrapper& operator=(PFCatalogGetEntityDraftItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetEntityDraftItemsRequestWrapper() = default;

    friend void swap(PFCatalogGetEntityDraftItemsRequestWrapper& lhs, PFCatalogGetEntityDraftItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetCount(int32_t value)
    {
        this->m_model.count = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
    }

    String m_continuationToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetEntityDraftItemsResponseWrapper : public ModelWrapper<PFCatalogGetEntityDraftItemsResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetEntityDraftItemsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetEntityDraftItemsResponseWrapper() = default;

    PFCatalogGetEntityDraftItemsResponseWrapper(const PFCatalogGetEntityDraftItemsResponse& model) :
        ModelWrapper<PFCatalogGetEntityDraftItemsResponse, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFCatalogGetEntityDraftItemsResponseWrapper(const PFCatalogGetEntityDraftItemsResponseWrapper& src) :
        PFCatalogGetEntityDraftItemsResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetEntityDraftItemsResponseWrapper(PFCatalogGetEntityDraftItemsResponseWrapper&& src) :
        PFCatalogGetEntityDraftItemsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetEntityDraftItemsResponseWrapper& operator=(PFCatalogGetEntityDraftItemsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetEntityDraftItemsResponseWrapper() = default;

    friend void swap(PFCatalogGetEntityDraftItemsResponseWrapper& lhs, PFCatalogGetEntityDraftItemsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetItems(ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    String m_continuationToken;
    ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetEntityItemReviewRequestWrapper : public ModelWrapper<PFCatalogGetEntityItemReviewRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetEntityItemReviewRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetEntityItemReviewRequestWrapper() = default;

    PFCatalogGetEntityItemReviewRequestWrapper(const PFCatalogGetEntityItemReviewRequest& model) :
        ModelWrapper<PFCatalogGetEntityItemReviewRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetEntityItemReviewRequestWrapper(const PFCatalogGetEntityItemReviewRequestWrapper& src) :
        PFCatalogGetEntityItemReviewRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetEntityItemReviewRequestWrapper(PFCatalogGetEntityItemReviewRequestWrapper&& src) :
        PFCatalogGetEntityItemReviewRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetEntityItemReviewRequestWrapper& operator=(PFCatalogGetEntityItemReviewRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetEntityItemReviewRequestWrapper() = default;

    friend void swap(PFCatalogGetEntityItemReviewRequestWrapper& lhs, PFCatalogGetEntityItemReviewRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogReviewWrapper : public ModelWrapper<PFCatalogReview, Alloc>
{
public:
    using ModelType = typename PFCatalogReview;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogReviewWrapper() = default;

    PFCatalogReviewWrapper(const PFCatalogReview& model) :
        ModelWrapper<PFCatalogReview, Alloc>{ model },
        m_itemId{ SafeString(model.itemId) },
        m_itemVersion{ SafeString(model.itemVersion) },
        m_locale{ SafeString(model.locale) },
        m_reviewerId{ SafeString(model.reviewerId) },
        m_reviewId{ SafeString(model.reviewId) },
        m_reviewText{ SafeString(model.reviewText) },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFCatalogReviewWrapper(const PFCatalogReviewWrapper& src) :
        PFCatalogReviewWrapper{ src.Model() }
    {
    }

    PFCatalogReviewWrapper(PFCatalogReviewWrapper&& src) :
        PFCatalogReviewWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogReviewWrapper& operator=(PFCatalogReviewWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogReviewWrapper() = default;

    friend void swap(PFCatalogReviewWrapper& lhs, PFCatalogReviewWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_itemVersion, rhs.m_itemVersion);
        swap(lhs.m_locale, rhs.m_locale);
        swap(lhs.m_reviewerId, rhs.m_reviewerId);
        swap(lhs.m_reviewId, rhs.m_reviewId);
        swap(lhs.m_reviewText, rhs.m_reviewText);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetHelpfulNegative(int32_t value)
    {
        this->m_model.helpfulNegative = value;
    }

    void SetHelpfulnessVotes(int32_t value)
    {
        this->m_model.helpfulnessVotes = value;
    }

    void SetHelpfulPositive(int32_t value)
    {
        this->m_model.helpfulPositive = value;
    }

    void SetIsInstalled(bool value)
    {
        this->m_model.isInstalled = value;
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetItemVersion(String value)
    {
        m_itemVersion = std::move(value);
        this->m_model.itemVersion =  m_itemVersion.empty() ? nullptr : m_itemVersion.data();
    }

    void SetLocale(String value)
    {
        m_locale = std::move(value);
        this->m_model.locale =  m_locale.empty() ? nullptr : m_locale.data();
    }

    void SetRating(int32_t value)
    {
        this->m_model.rating = value;
    }

    void SetReviewerId(String value)
    {
        m_reviewerId = std::move(value);
        this->m_model.reviewerId =  m_reviewerId.empty() ? nullptr : m_reviewerId.data();
    }

    void SetReviewId(String value)
    {
        m_reviewId = std::move(value);
        this->m_model.reviewId =  m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

    void SetReviewText(String value)
    {
        m_reviewText = std::move(value);
        this->m_model.reviewText =  m_reviewText.empty() ? nullptr : m_reviewText.data();
    }

    void SetSubmitted(time_t value)
    {
        this->m_model.submitted = value;
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.itemVersion = m_itemVersion.empty() ? nullptr : m_itemVersion.data();
        this->m_model.locale = m_locale.empty() ? nullptr : m_locale.data();
        this->m_model.reviewerId = m_reviewerId.empty() ? nullptr : m_reviewerId.data();
        this->m_model.reviewId = m_reviewId.empty() ? nullptr : m_reviewId.data();
        this->m_model.reviewText = m_reviewText.empty() ? nullptr : m_reviewText.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_itemId;
    String m_itemVersion;
    String m_locale;
    String m_reviewerId;
    String m_reviewId;
    String m_reviewText;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetEntityItemReviewResponseWrapper : public ModelWrapper<PFCatalogGetEntityItemReviewResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetEntityItemReviewResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetEntityItemReviewResponseWrapper() = default;

    PFCatalogGetEntityItemReviewResponseWrapper(const PFCatalogGetEntityItemReviewResponse& model) :
        ModelWrapper<PFCatalogGetEntityItemReviewResponse, Alloc>{ model },
        m_review{ model.review ? StdExtra::optional<PFCatalogReviewWrapper<Alloc>>{ *model.review } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetEntityItemReviewResponseWrapper(const PFCatalogGetEntityItemReviewResponseWrapper& src) :
        PFCatalogGetEntityItemReviewResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetEntityItemReviewResponseWrapper(PFCatalogGetEntityItemReviewResponseWrapper&& src) :
        PFCatalogGetEntityItemReviewResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetEntityItemReviewResponseWrapper& operator=(PFCatalogGetEntityItemReviewResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetEntityItemReviewResponseWrapper() = default;

    friend void swap(PFCatalogGetEntityItemReviewResponseWrapper& lhs, PFCatalogGetEntityItemReviewResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_review, rhs.m_review);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetReview(StdExtra::optional<PFCatalogReviewWrapper<Alloc>> value)
    {
        m_review = std::move(value);
        this->m_model.review = m_review ? &m_review->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.review = m_review ?  &m_review->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogReviewWrapper<Alloc>> m_review;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemRequestWrapper : public ModelWrapper<PFCatalogGetItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemRequestWrapper() = default;

    PFCatalogGetItemRequestWrapper(const PFCatalogGetItemRequest& model) :
        ModelWrapper<PFCatalogGetItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemRequestWrapper(const PFCatalogGetItemRequestWrapper& src) :
        PFCatalogGetItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemRequestWrapper(PFCatalogGetItemRequestWrapper&& src) :
        PFCatalogGetItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemRequestWrapper& operator=(PFCatalogGetItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemRequestWrapper() = default;

    friend void swap(PFCatalogGetItemRequestWrapper& lhs, PFCatalogGetItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemResponseWrapper : public ModelWrapper<PFCatalogGetItemResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemResponseWrapper() = default;

    PFCatalogGetItemResponseWrapper(const PFCatalogGetItemResponse& model) :
        ModelWrapper<PFCatalogGetItemResponse, Alloc>{ model },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetItemResponseWrapper(const PFCatalogGetItemResponseWrapper& src) :
        PFCatalogGetItemResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemResponseWrapper(PFCatalogGetItemResponseWrapper&& src) :
        PFCatalogGetItemResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemResponseWrapper& operator=(PFCatalogGetItemResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemResponseWrapper() = default;

    friend void swap(PFCatalogGetItemResponseWrapper& lhs, PFCatalogGetItemResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemModerationStateRequestWrapper : public ModelWrapper<PFCatalogGetItemModerationStateRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemModerationStateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemModerationStateRequestWrapper() = default;

    PFCatalogGetItemModerationStateRequestWrapper(const PFCatalogGetItemModerationStateRequest& model) :
        ModelWrapper<PFCatalogGetItemModerationStateRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemModerationStateRequestWrapper(const PFCatalogGetItemModerationStateRequestWrapper& src) :
        PFCatalogGetItemModerationStateRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemModerationStateRequestWrapper(PFCatalogGetItemModerationStateRequestWrapper&& src) :
        PFCatalogGetItemModerationStateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemModerationStateRequestWrapper& operator=(PFCatalogGetItemModerationStateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemModerationStateRequestWrapper() = default;

    friend void swap(PFCatalogGetItemModerationStateRequestWrapper& lhs, PFCatalogGetItemModerationStateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemModerationStateResponseWrapper : public ModelWrapper<PFCatalogGetItemModerationStateResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemModerationStateResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemModerationStateResponseWrapper() = default;

    PFCatalogGetItemModerationStateResponseWrapper(const PFCatalogGetItemModerationStateResponse& model) :
        ModelWrapper<PFCatalogGetItemModerationStateResponse, Alloc>{ model },
        m_state{ model.state ? StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>>{ *model.state } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetItemModerationStateResponseWrapper(const PFCatalogGetItemModerationStateResponseWrapper& src) :
        PFCatalogGetItemModerationStateResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemModerationStateResponseWrapper(PFCatalogGetItemModerationStateResponseWrapper&& src) :
        PFCatalogGetItemModerationStateResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemModerationStateResponseWrapper& operator=(PFCatalogGetItemModerationStateResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemModerationStateResponseWrapper() = default;

    friend void swap(PFCatalogGetItemModerationStateResponseWrapper& lhs, PFCatalogGetItemModerationStateResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_state, rhs.m_state);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetState(StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>> value)
    {
        m_state = std::move(value);
        this->m_model.state = m_state ? &m_state->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.state = m_state ?  &m_state->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogModerationStateWrapper<Alloc>> m_state;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemPublishStatusRequestWrapper : public ModelWrapper<PFCatalogGetItemPublishStatusRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemPublishStatusRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemPublishStatusRequestWrapper() = default;

    PFCatalogGetItemPublishStatusRequestWrapper(const PFCatalogGetItemPublishStatusRequest& model) :
        ModelWrapper<PFCatalogGetItemPublishStatusRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemPublishStatusRequestWrapper(const PFCatalogGetItemPublishStatusRequestWrapper& src) :
        PFCatalogGetItemPublishStatusRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemPublishStatusRequestWrapper(PFCatalogGetItemPublishStatusRequestWrapper&& src) :
        PFCatalogGetItemPublishStatusRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemPublishStatusRequestWrapper& operator=(PFCatalogGetItemPublishStatusRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemPublishStatusRequestWrapper() = default;

    friend void swap(PFCatalogGetItemPublishStatusRequestWrapper& lhs, PFCatalogGetItemPublishStatusRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogScanResultWrapper : public ModelWrapper<PFCatalogScanResult, Alloc>
{
public:
    using ModelType = typename PFCatalogScanResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogScanResultWrapper() = default;

    PFCatalogScanResultWrapper(const PFCatalogScanResult& model) :
        ModelWrapper<PFCatalogScanResult, Alloc>{ model },
        m_url{ SafeString(model.url) }
    {
        SetModelPointers();
    }

    PFCatalogScanResultWrapper(const PFCatalogScanResultWrapper& src) :
        PFCatalogScanResultWrapper{ src.Model() }
    {
    }

    PFCatalogScanResultWrapper(PFCatalogScanResultWrapper&& src) :
        PFCatalogScanResultWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogScanResultWrapper& operator=(PFCatalogScanResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogScanResultWrapper() = default;

    friend void swap(PFCatalogScanResultWrapper& lhs, PFCatalogScanResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_url, rhs.m_url);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUrl(String value)
    {
        m_url = std::move(value);
        this->m_model.url =  m_url.empty() ? nullptr : m_url.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.url = m_url.empty() ? nullptr : m_url.data();
    }

    String m_url;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemPublishStatusResponseWrapper : public ModelWrapper<PFCatalogGetItemPublishStatusResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemPublishStatusResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemPublishStatusResponseWrapper() = default;

    PFCatalogGetItemPublishStatusResponseWrapper(const PFCatalogGetItemPublishStatusResponse& model) :
        ModelWrapper<PFCatalogGetItemPublishStatusResponse, Alloc>{ model },
        m_failedScanResults{ model.failedScanResults, model.failedScanResults + model.failedScanResultsCount },
        m_result{ model.result ? StdExtra::optional<PFCatalogPublishResult>{ *model.result } : StdExtra::nullopt },
        m_statusMessage{ SafeString(model.statusMessage) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemPublishStatusResponseWrapper(const PFCatalogGetItemPublishStatusResponseWrapper& src) :
        PFCatalogGetItemPublishStatusResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemPublishStatusResponseWrapper(PFCatalogGetItemPublishStatusResponseWrapper&& src) :
        PFCatalogGetItemPublishStatusResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemPublishStatusResponseWrapper& operator=(PFCatalogGetItemPublishStatusResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemPublishStatusResponseWrapper() = default;

    friend void swap(PFCatalogGetItemPublishStatusResponseWrapper& lhs, PFCatalogGetItemPublishStatusResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_failedScanResults, rhs.m_failedScanResults);
        swap(lhs.m_result, rhs.m_result);
        swap(lhs.m_statusMessage, rhs.m_statusMessage);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFailedScanResults(ModelVector<PFCatalogScanResultWrapper<Alloc>, Alloc> value)
    {
        m_failedScanResults = std::move(value);
        this->m_model.failedScanResults =  m_failedScanResults.empty() ? nullptr : m_failedScanResults.data();
        this->m_model.failedScanResultsCount =  static_cast<uint32_t>(m_failedScanResults.size());
    }

    void SetResult(StdExtra::optional<PFCatalogPublishResult> value)
    {
        m_result = std::move(value);
        this->m_model.result = m_result ? m_result.operator->() : nullptr;
    }

    void SetStatusMessage(String value)
    {
        m_statusMessage = std::move(value);
        this->m_model.statusMessage =  m_statusMessage.empty() ? nullptr : m_statusMessage.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.failedScanResults = m_failedScanResults.empty() ? nullptr : m_failedScanResults.data();
        this->m_model.result = m_result ? m_result.operator->() : nullptr;
        this->m_model.statusMessage = m_statusMessage.empty() ? nullptr : m_statusMessage.data();
    }

    ModelVector<PFCatalogScanResultWrapper<Alloc>, Alloc> m_failedScanResults;
    StdExtra::optional<PFCatalogPublishResult> m_result;
    String m_statusMessage;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemReviewsRequestWrapper : public ModelWrapper<PFCatalogGetItemReviewsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemReviewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemReviewsRequestWrapper() = default;

    PFCatalogGetItemReviewsRequestWrapper(const PFCatalogGetItemReviewsRequest& model) :
        ModelWrapper<PFCatalogGetItemReviewsRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_id{ SafeString(model.id) },
        m_orderBy{ SafeString(model.orderBy) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemReviewsRequestWrapper(const PFCatalogGetItemReviewsRequestWrapper& src) :
        PFCatalogGetItemReviewsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemReviewsRequestWrapper(PFCatalogGetItemReviewsRequestWrapper&& src) :
        PFCatalogGetItemReviewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemReviewsRequestWrapper& operator=(PFCatalogGetItemReviewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemReviewsRequestWrapper() = default;

    friend void swap(PFCatalogGetItemReviewsRequestWrapper& lhs, PFCatalogGetItemReviewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_orderBy, rhs.m_orderBy);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetCount(int32_t value)
    {
        this->m_model.count = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetOrderBy(String value)
    {
        m_orderBy = std::move(value);
        this->m_model.orderBy =  m_orderBy.empty() ? nullptr : m_orderBy.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.orderBy = m_orderBy.empty() ? nullptr : m_orderBy.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    String m_continuationToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_id;
    String m_orderBy;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemReviewsResponseWrapper : public ModelWrapper<PFCatalogGetItemReviewsResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemReviewsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemReviewsResponseWrapper() = default;

    PFCatalogGetItemReviewsResponseWrapper(const PFCatalogGetItemReviewsResponse& model) :
        ModelWrapper<PFCatalogGetItemReviewsResponse, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_reviews{ model.reviews, model.reviews + model.reviewsCount }
    {
        SetModelPointers();
    }

    PFCatalogGetItemReviewsResponseWrapper(const PFCatalogGetItemReviewsResponseWrapper& src) :
        PFCatalogGetItemReviewsResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemReviewsResponseWrapper(PFCatalogGetItemReviewsResponseWrapper&& src) :
        PFCatalogGetItemReviewsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemReviewsResponseWrapper& operator=(PFCatalogGetItemReviewsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemReviewsResponseWrapper() = default;

    friend void swap(PFCatalogGetItemReviewsResponseWrapper& lhs, PFCatalogGetItemReviewsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_reviews, rhs.m_reviews);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetReviews(ModelVector<PFCatalogReviewWrapper<Alloc>, Alloc> value)
    {
        m_reviews = std::move(value);
        this->m_model.reviews =  m_reviews.empty() ? nullptr : m_reviews.data();
        this->m_model.reviewsCount =  static_cast<uint32_t>(m_reviews.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.reviews = m_reviews.empty() ? nullptr : m_reviews.data();
    }

    String m_continuationToken;
    ModelVector<PFCatalogReviewWrapper<Alloc>, Alloc> m_reviews;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemReviewSummaryRequestWrapper : public ModelWrapper<PFCatalogGetItemReviewSummaryRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemReviewSummaryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemReviewSummaryRequestWrapper() = default;

    PFCatalogGetItemReviewSummaryRequestWrapper(const PFCatalogGetItemReviewSummaryRequest& model) :
        ModelWrapper<PFCatalogGetItemReviewSummaryRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogGetItemReviewSummaryRequestWrapper(const PFCatalogGetItemReviewSummaryRequestWrapper& src) :
        PFCatalogGetItemReviewSummaryRequestWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemReviewSummaryRequestWrapper(PFCatalogGetItemReviewSummaryRequestWrapper&& src) :
        PFCatalogGetItemReviewSummaryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemReviewSummaryRequestWrapper& operator=(PFCatalogGetItemReviewSummaryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemReviewSummaryRequestWrapper() = default;

    friend void swap(PFCatalogGetItemReviewSummaryRequestWrapper& lhs, PFCatalogGetItemReviewSummaryRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogGetItemReviewSummaryResponseWrapper : public ModelWrapper<PFCatalogGetItemReviewSummaryResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogGetItemReviewSummaryResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogGetItemReviewSummaryResponseWrapper() = default;

    PFCatalogGetItemReviewSummaryResponseWrapper(const PFCatalogGetItemReviewSummaryResponse& model) :
        ModelWrapper<PFCatalogGetItemReviewSummaryResponse, Alloc>{ model },
        m_leastFavorableReview{ model.leastFavorableReview ? StdExtra::optional<PFCatalogReviewWrapper<Alloc>>{ *model.leastFavorableReview } : StdExtra::nullopt },
        m_mostFavorableReview{ model.mostFavorableReview ? StdExtra::optional<PFCatalogReviewWrapper<Alloc>>{ *model.mostFavorableReview } : StdExtra::nullopt },
        m_rating{ model.rating ? StdExtra::optional<PFCatalogRatingWrapper<Alloc>>{ *model.rating } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogGetItemReviewSummaryResponseWrapper(const PFCatalogGetItemReviewSummaryResponseWrapper& src) :
        PFCatalogGetItemReviewSummaryResponseWrapper{ src.Model() }
    {
    }

    PFCatalogGetItemReviewSummaryResponseWrapper(PFCatalogGetItemReviewSummaryResponseWrapper&& src) :
        PFCatalogGetItemReviewSummaryResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogGetItemReviewSummaryResponseWrapper& operator=(PFCatalogGetItemReviewSummaryResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogGetItemReviewSummaryResponseWrapper() = default;

    friend void swap(PFCatalogGetItemReviewSummaryResponseWrapper& lhs, PFCatalogGetItemReviewSummaryResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leastFavorableReview, rhs.m_leastFavorableReview);
        swap(lhs.m_mostFavorableReview, rhs.m_mostFavorableReview);
        swap(lhs.m_rating, rhs.m_rating);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeastFavorableReview(StdExtra::optional<PFCatalogReviewWrapper<Alloc>> value)
    {
        m_leastFavorableReview = std::move(value);
        this->m_model.leastFavorableReview = m_leastFavorableReview ? &m_leastFavorableReview->Model() : nullptr;
    }

    void SetMostFavorableReview(StdExtra::optional<PFCatalogReviewWrapper<Alloc>> value)
    {
        m_mostFavorableReview = std::move(value);
        this->m_model.mostFavorableReview = m_mostFavorableReview ? &m_mostFavorableReview->Model() : nullptr;
    }

    void SetRating(StdExtra::optional<PFCatalogRatingWrapper<Alloc>> value)
    {
        m_rating = std::move(value);
        this->m_model.rating = m_rating ? &m_rating->Model() : nullptr;
    }

    void SetReviewsCount(int32_t value)
    {
        this->m_model.reviewsCount = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.leastFavorableReview = m_leastFavorableReview ?  &m_leastFavorableReview->Model() : nullptr;
        this->m_model.mostFavorableReview = m_mostFavorableReview ?  &m_mostFavorableReview->Model() : nullptr;
        this->m_model.rating = m_rating ?  &m_rating->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogReviewWrapper<Alloc>> m_leastFavorableReview;
    StdExtra::optional<PFCatalogReviewWrapper<Alloc>> m_mostFavorableReview;
    StdExtra::optional<PFCatalogRatingWrapper<Alloc>> m_rating;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogPublishDraftItemRequestWrapper : public ModelWrapper<PFCatalogPublishDraftItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogPublishDraftItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogPublishDraftItemRequestWrapper() = default;

    PFCatalogPublishDraftItemRequestWrapper(const PFCatalogPublishDraftItemRequest& model) :
        ModelWrapper<PFCatalogPublishDraftItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_eTag{ SafeString(model.eTag) },
        m_id{ SafeString(model.id) }
    {
        SetModelPointers();
    }

    PFCatalogPublishDraftItemRequestWrapper(const PFCatalogPublishDraftItemRequestWrapper& src) :
        PFCatalogPublishDraftItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogPublishDraftItemRequestWrapper(PFCatalogPublishDraftItemRequestWrapper&& src) :
        PFCatalogPublishDraftItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogPublishDraftItemRequestWrapper& operator=(PFCatalogPublishDraftItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogPublishDraftItemRequestWrapper() = default;

    friend void swap(PFCatalogPublishDraftItemRequestWrapper& lhs, PFCatalogPublishDraftItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_eTag, rhs.m_eTag);
        swap(lhs.m_id, rhs.m_id);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetETag(String value)
    {
        m_eTag = std::move(value);
        this->m_model.eTag =  m_eTag.empty() ? nullptr : m_eTag.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.eTag = m_eTag.empty() ? nullptr : m_eTag.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_eTag;
    String m_id;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogReportItemRequestWrapper : public ModelWrapper<PFCatalogReportItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogReportItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogReportItemRequestWrapper() = default;

    PFCatalogReportItemRequestWrapper(const PFCatalogReportItemRequest& model) :
        ModelWrapper<PFCatalogReportItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_concernCategory{ model.concernCategory ? StdExtra::optional<PFCatalogConcernCategory>{ *model.concernCategory } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFCatalogReportItemRequestWrapper(const PFCatalogReportItemRequestWrapper& src) :
        PFCatalogReportItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogReportItemRequestWrapper(PFCatalogReportItemRequestWrapper&& src) :
        PFCatalogReportItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogReportItemRequestWrapper& operator=(PFCatalogReportItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogReportItemRequestWrapper() = default;

    friend void swap(PFCatalogReportItemRequestWrapper& lhs, PFCatalogReportItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_concernCategory, rhs.m_concernCategory);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetConcernCategory(StdExtra::optional<PFCatalogConcernCategory> value)
    {
        m_concernCategory = std::move(value);
        this->m_model.concernCategory = m_concernCategory ? m_concernCategory.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.concernCategory = m_concernCategory ? m_concernCategory.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StdExtra::optional<PFCatalogConcernCategory> m_concernCategory;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogReportItemReviewRequestWrapper : public ModelWrapper<PFCatalogReportItemReviewRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogReportItemReviewRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogReportItemReviewRequestWrapper() = default;

    PFCatalogReportItemReviewRequestWrapper(const PFCatalogReportItemReviewRequest& model) :
        ModelWrapper<PFCatalogReportItemReviewRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_concernCategory{ model.concernCategory ? StdExtra::optional<PFCatalogConcernCategory>{ *model.concernCategory } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_itemId{ SafeString(model.itemId) },
        m_reason{ SafeString(model.reason) },
        m_reviewId{ SafeString(model.reviewId) }
    {
        SetModelPointers();
    }

    PFCatalogReportItemReviewRequestWrapper(const PFCatalogReportItemReviewRequestWrapper& src) :
        PFCatalogReportItemReviewRequestWrapper{ src.Model() }
    {
    }

    PFCatalogReportItemReviewRequestWrapper(PFCatalogReportItemReviewRequestWrapper&& src) :
        PFCatalogReportItemReviewRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogReportItemReviewRequestWrapper& operator=(PFCatalogReportItemReviewRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogReportItemReviewRequestWrapper() = default;

    friend void swap(PFCatalogReportItemReviewRequestWrapper& lhs, PFCatalogReportItemReviewRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_concernCategory, rhs.m_concernCategory);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_reason, rhs.m_reason);
        swap(lhs.m_reviewId, rhs.m_reviewId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetConcernCategory(StdExtra::optional<PFCatalogConcernCategory> value)
    {
        m_concernCategory = std::move(value);
        this->m_model.concernCategory = m_concernCategory ? m_concernCategory.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

    void SetReviewId(String value)
    {
        m_reviewId = std::move(value);
        this->m_model.reviewId =  m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.concernCategory = m_concernCategory ? m_concernCategory.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
        this->m_model.reviewId = m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StdExtra::optional<PFCatalogConcernCategory> m_concernCategory;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_itemId;
    String m_reason;
    String m_reviewId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogReviewItemRequestWrapper : public ModelWrapper<PFCatalogReviewItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogReviewItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogReviewItemRequestWrapper() = default;

    PFCatalogReviewItemRequestWrapper(const PFCatalogReviewItemRequest& model) :
        ModelWrapper<PFCatalogReviewItemRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_id{ SafeString(model.id) },
        m_review{ model.review ? StdExtra::optional<PFCatalogReviewWrapper<Alloc>>{ *model.review } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogReviewItemRequestWrapper(const PFCatalogReviewItemRequestWrapper& src) :
        PFCatalogReviewItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogReviewItemRequestWrapper(PFCatalogReviewItemRequestWrapper&& src) :
        PFCatalogReviewItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogReviewItemRequestWrapper& operator=(PFCatalogReviewItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogReviewItemRequestWrapper() = default;

    friend void swap(PFCatalogReviewItemRequestWrapper& lhs, PFCatalogReviewItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_review, rhs.m_review);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetReview(StdExtra::optional<PFCatalogReviewWrapper<Alloc>> value)
    {
        m_review = std::move(value);
        this->m_model.review = m_review ? &m_review->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.review = m_review ?  &m_review->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_id;
    StdExtra::optional<PFCatalogReviewWrapper<Alloc>> m_review;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogSearchItemsRequestWrapper : public ModelWrapper<PFCatalogSearchItemsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogSearchItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogSearchItemsRequestWrapper() = default;

    PFCatalogSearchItemsRequestWrapper(const PFCatalogSearchItemsRequest& model) :
        ModelWrapper<PFCatalogSearchItemsRequest, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_filter{ SafeString(model.filter) },
        m_orderBy{ SafeString(model.orderBy) },
        m_search{ SafeString(model.search) },
        m_select{ SafeString(model.select) }
    {
        SetModelPointers();
    }

    PFCatalogSearchItemsRequestWrapper(const PFCatalogSearchItemsRequestWrapper& src) :
        PFCatalogSearchItemsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogSearchItemsRequestWrapper(PFCatalogSearchItemsRequestWrapper&& src) :
        PFCatalogSearchItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogSearchItemsRequestWrapper& operator=(PFCatalogSearchItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogSearchItemsRequestWrapper() = default;

    friend void swap(PFCatalogSearchItemsRequestWrapper& lhs, PFCatalogSearchItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_filter, rhs.m_filter);
        swap(lhs.m_orderBy, rhs.m_orderBy);
        swap(lhs.m_search, rhs.m_search);
        swap(lhs.m_select, rhs.m_select);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetCount(int32_t value)
    {
        this->m_model.count = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetFilter(String value)
    {
        m_filter = std::move(value);
        this->m_model.filter =  m_filter.empty() ? nullptr : m_filter.data();
    }

    void SetOrderBy(String value)
    {
        m_orderBy = std::move(value);
        this->m_model.orderBy =  m_orderBy.empty() ? nullptr : m_orderBy.data();
    }

    void SetSearch(String value)
    {
        m_search = std::move(value);
        this->m_model.search =  m_search.empty() ? nullptr : m_search.data();
    }

    void SetSelect(String value)
    {
        m_select = std::move(value);
        this->m_model.select =  m_select.empty() ? nullptr : m_select.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.filter = m_filter.empty() ? nullptr : m_filter.data();
        this->m_model.orderBy = m_orderBy.empty() ? nullptr : m_orderBy.data();
        this->m_model.search = m_search.empty() ? nullptr : m_search.data();
        this->m_model.select = m_select.empty() ? nullptr : m_select.data();
    }

    String m_continuationToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_filter;
    String m_orderBy;
    String m_search;
    String m_select;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogSearchItemsResponseWrapper : public ModelWrapper<PFCatalogSearchItemsResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogSearchItemsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogSearchItemsResponseWrapper() = default;

    PFCatalogSearchItemsResponseWrapper(const PFCatalogSearchItemsResponse& model) :
        ModelWrapper<PFCatalogSearchItemsResponse, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFCatalogSearchItemsResponseWrapper(const PFCatalogSearchItemsResponseWrapper& src) :
        PFCatalogSearchItemsResponseWrapper{ src.Model() }
    {
    }

    PFCatalogSearchItemsResponseWrapper(PFCatalogSearchItemsResponseWrapper&& src) :
        PFCatalogSearchItemsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogSearchItemsResponseWrapper& operator=(PFCatalogSearchItemsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogSearchItemsResponseWrapper() = default;

    friend void swap(PFCatalogSearchItemsResponseWrapper& lhs, PFCatalogSearchItemsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetItems(ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    String m_continuationToken;
    ModelVector<PFCatalogCatalogItemWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogSetItemModerationStateRequestWrapper : public ModelWrapper<PFCatalogSetItemModerationStateRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogSetItemModerationStateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogSetItemModerationStateRequestWrapper() = default;

    PFCatalogSetItemModerationStateRequestWrapper(const PFCatalogSetItemModerationStateRequest& model) :
        ModelWrapper<PFCatalogSetItemModerationStateRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_id{ SafeString(model.id) },
        m_reason{ SafeString(model.reason) },
        m_status{ model.status ? StdExtra::optional<PFCatalogModerationStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogSetItemModerationStateRequestWrapper(const PFCatalogSetItemModerationStateRequestWrapper& src) :
        PFCatalogSetItemModerationStateRequestWrapper{ src.Model() }
    {
    }

    PFCatalogSetItemModerationStateRequestWrapper(PFCatalogSetItemModerationStateRequestWrapper&& src) :
        PFCatalogSetItemModerationStateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogSetItemModerationStateRequestWrapper& operator=(PFCatalogSetItemModerationStateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogSetItemModerationStateRequestWrapper() = default;

    friend void swap(PFCatalogSetItemModerationStateRequestWrapper& lhs, PFCatalogSetItemModerationStateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_reason, rhs.m_reason);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

    void SetStatus(StdExtra::optional<PFCatalogModerationStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_id;
    String m_reason;
    StdExtra::optional<PFCatalogModerationStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogSubmitItemReviewVoteRequestWrapper : public ModelWrapper<PFCatalogSubmitItemReviewVoteRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogSubmitItemReviewVoteRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogSubmitItemReviewVoteRequestWrapper() = default;

    PFCatalogSubmitItemReviewVoteRequestWrapper(const PFCatalogSubmitItemReviewVoteRequest& model) :
        ModelWrapper<PFCatalogSubmitItemReviewVoteRequest, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_itemId{ SafeString(model.itemId) },
        m_reviewId{ SafeString(model.reviewId) },
        m_vote{ model.vote ? StdExtra::optional<PFCatalogHelpfulnessVote>{ *model.vote } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogSubmitItemReviewVoteRequestWrapper(const PFCatalogSubmitItemReviewVoteRequestWrapper& src) :
        PFCatalogSubmitItemReviewVoteRequestWrapper{ src.Model() }
    {
    }

    PFCatalogSubmitItemReviewVoteRequestWrapper(PFCatalogSubmitItemReviewVoteRequestWrapper&& src) :
        PFCatalogSubmitItemReviewVoteRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogSubmitItemReviewVoteRequestWrapper& operator=(PFCatalogSubmitItemReviewVoteRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogSubmitItemReviewVoteRequestWrapper() = default;

    friend void swap(PFCatalogSubmitItemReviewVoteRequestWrapper& lhs, PFCatalogSubmitItemReviewVoteRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_reviewId, rhs.m_reviewId);
        swap(lhs.m_vote, rhs.m_vote);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetReviewId(String value)
    {
        m_reviewId = std::move(value);
        this->m_model.reviewId =  m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

    void SetVote(StdExtra::optional<PFCatalogHelpfulnessVote> value)
    {
        m_vote = std::move(value);
        this->m_model.vote = m_vote ? m_vote.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.reviewId = m_reviewId.empty() ? nullptr : m_reviewId.data();
        this->m_model.vote = m_vote ? m_vote.operator->() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_itemId;
    String m_reviewId;
    StdExtra::optional<PFCatalogHelpfulnessVote> m_vote;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogReviewTakedownWrapper : public ModelWrapper<PFCatalogReviewTakedown, Alloc>
{
public:
    using ModelType = typename PFCatalogReviewTakedown;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogReviewTakedownWrapper() = default;

    PFCatalogReviewTakedownWrapper(const PFCatalogReviewTakedown& model) :
        ModelWrapper<PFCatalogReviewTakedown, Alloc>{ model },
        m_alternateId{ model.alternateId ? StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>>{ *model.alternateId } : StdExtra::nullopt },
        m_itemId{ SafeString(model.itemId) },
        m_reviewId{ SafeString(model.reviewId) }
    {
        SetModelPointers();
    }

    PFCatalogReviewTakedownWrapper(const PFCatalogReviewTakedownWrapper& src) :
        PFCatalogReviewTakedownWrapper{ src.Model() }
    {
    }

    PFCatalogReviewTakedownWrapper(PFCatalogReviewTakedownWrapper&& src) :
        PFCatalogReviewTakedownWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogReviewTakedownWrapper& operator=(PFCatalogReviewTakedownWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogReviewTakedownWrapper() = default;

    friend void swap(PFCatalogReviewTakedownWrapper& lhs, PFCatalogReviewTakedownWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_alternateId, rhs.m_alternateId);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_reviewId, rhs.m_reviewId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAlternateId(StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> value)
    {
        m_alternateId = std::move(value);
        this->m_model.alternateId = m_alternateId ? &m_alternateId->Model() : nullptr;
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetReviewId(String value)
    {
        m_reviewId = std::move(value);
        this->m_model.reviewId =  m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.alternateId = m_alternateId ?  &m_alternateId->Model() : nullptr;
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.reviewId = m_reviewId.empty() ? nullptr : m_reviewId.data();
    }

    StdExtra::optional<PFCatalogCatalogAlternateIdWrapper<Alloc>> m_alternateId;
    String m_itemId;
    String m_reviewId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogTakedownItemReviewsRequestWrapper : public ModelWrapper<PFCatalogTakedownItemReviewsRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogTakedownItemReviewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogTakedownItemReviewsRequestWrapper() = default;

    PFCatalogTakedownItemReviewsRequestWrapper(const PFCatalogTakedownItemReviewsRequest& model) :
        ModelWrapper<PFCatalogTakedownItemReviewsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_reviews{ model.reviews, model.reviews + model.reviewsCount }
    {
        SetModelPointers();
    }

    PFCatalogTakedownItemReviewsRequestWrapper(const PFCatalogTakedownItemReviewsRequestWrapper& src) :
        PFCatalogTakedownItemReviewsRequestWrapper{ src.Model() }
    {
    }

    PFCatalogTakedownItemReviewsRequestWrapper(PFCatalogTakedownItemReviewsRequestWrapper&& src) :
        PFCatalogTakedownItemReviewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogTakedownItemReviewsRequestWrapper& operator=(PFCatalogTakedownItemReviewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogTakedownItemReviewsRequestWrapper() = default;

    friend void swap(PFCatalogTakedownItemReviewsRequestWrapper& lhs, PFCatalogTakedownItemReviewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_reviews, rhs.m_reviews);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetReviews(ModelVector<PFCatalogReviewTakedownWrapper<Alloc>, Alloc> value)
    {
        m_reviews = std::move(value);
        this->m_model.reviews =  m_reviews.empty() ? nullptr : m_reviews.data();
        this->m_model.reviewsCount =  static_cast<uint32_t>(m_reviews.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.reviews = m_reviews.empty() ? nullptr : m_reviews.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFCatalogReviewTakedownWrapper<Alloc>, Alloc> m_reviews;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUpdateCatalogConfigRequestWrapper : public ModelWrapper<PFCatalogUpdateCatalogConfigRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogUpdateCatalogConfigRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUpdateCatalogConfigRequestWrapper() = default;

    PFCatalogUpdateCatalogConfigRequestWrapper(const PFCatalogUpdateCatalogConfigRequest& model) :
        ModelWrapper<PFCatalogUpdateCatalogConfigRequest, Alloc>{ model },
        m_config{ model.config ? StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>>{ *model.config } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFCatalogUpdateCatalogConfigRequestWrapper(const PFCatalogUpdateCatalogConfigRequestWrapper& src) :
        PFCatalogUpdateCatalogConfigRequestWrapper{ src.Model() }
    {
    }

    PFCatalogUpdateCatalogConfigRequestWrapper(PFCatalogUpdateCatalogConfigRequestWrapper&& src) :
        PFCatalogUpdateCatalogConfigRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUpdateCatalogConfigRequestWrapper& operator=(PFCatalogUpdateCatalogConfigRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUpdateCatalogConfigRequestWrapper() = default;

    friend void swap(PFCatalogUpdateCatalogConfigRequestWrapper& lhs, PFCatalogUpdateCatalogConfigRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_config, rhs.m_config);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConfig(StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>> value)
    {
        m_config = std::move(value);
        this->m_model.config = m_config ? &m_config->Model() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.config = m_config ?  &m_config->Model() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StdExtra::optional<PFCatalogCatalogConfigWrapper<Alloc>> m_config;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUpdateDraftItemRequestWrapper : public ModelWrapper<PFCatalogUpdateDraftItemRequest, Alloc>
{
public:
    using ModelType = typename PFCatalogUpdateDraftItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUpdateDraftItemRequestWrapper() = default;

    PFCatalogUpdateDraftItemRequestWrapper(const PFCatalogUpdateDraftItemRequest& model) :
        ModelWrapper<PFCatalogUpdateDraftItemRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogUpdateDraftItemRequestWrapper(const PFCatalogUpdateDraftItemRequestWrapper& src) :
        PFCatalogUpdateDraftItemRequestWrapper{ src.Model() }
    {
    }

    PFCatalogUpdateDraftItemRequestWrapper(PFCatalogUpdateDraftItemRequestWrapper&& src) :
        PFCatalogUpdateDraftItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUpdateDraftItemRequestWrapper& operator=(PFCatalogUpdateDraftItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUpdateDraftItemRequestWrapper() = default;

    friend void swap(PFCatalogUpdateDraftItemRequestWrapper& lhs, PFCatalogUpdateDraftItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

    void SetPublish(bool value)
    {
        this->m_model.publish = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCatalogUpdateDraftItemResponseWrapper : public ModelWrapper<PFCatalogUpdateDraftItemResponse, Alloc>
{
public:
    using ModelType = typename PFCatalogUpdateDraftItemResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCatalogUpdateDraftItemResponseWrapper() = default;

    PFCatalogUpdateDraftItemResponseWrapper(const PFCatalogUpdateDraftItemResponse& model) :
        ModelWrapper<PFCatalogUpdateDraftItemResponse, Alloc>{ model },
        m_item{ model.item ? StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCatalogUpdateDraftItemResponseWrapper(const PFCatalogUpdateDraftItemResponseWrapper& src) :
        PFCatalogUpdateDraftItemResponseWrapper{ src.Model() }
    {
    }

    PFCatalogUpdateDraftItemResponseWrapper(PFCatalogUpdateDraftItemResponseWrapper&& src) :
        PFCatalogUpdateDraftItemResponseWrapper{}
    {
        swap(*this, src);
    }

    PFCatalogUpdateDraftItemResponseWrapper& operator=(PFCatalogUpdateDraftItemResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCatalogUpdateDraftItemResponseWrapper() = default;

    friend void swap(PFCatalogUpdateDraftItemResponseWrapper& lhs, PFCatalogUpdateDraftItemResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItem(StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StdExtra::optional<PFCatalogCatalogItemWrapper<Alloc>> m_item;
};

} // namespace Wrappers
} // namespace PlayFab
