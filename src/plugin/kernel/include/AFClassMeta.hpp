/*
 * This source file is part of ArkNX
 * For the latest info, see https://github.com/ArkNX
 *
 * Copyright (c) 2013-2019 ArkNX authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include "base/AFMacros.hpp"
#include "base/AFMap.hpp"
#include "base/AFDefine.hpp"
#include "base/AFEnum.hpp"
#include "AFNodeMeta.hpp"
#include "AFTableMeta.hpp"
#include "AFClassCallBackManager.hpp"
#include "AFContainerMeta.hpp"

namespace ark {

class AFTableMeta;

class AFClassMeta final
{
public:
    using NameIndexList = std::unordered_map<std::string, uint32_t>;
    using DataMetaList = AFSmartPtrMap<uint32_t, AFNodeMeta>;
    using TableMetaList = AFSmartPtrMap<uint32_t, AFTableMeta>;
    using ContainerMetaList = AFSmartPtrMap<uint32_t, AFContainerMeta>;

private:
    // class name
    std::string name_{NULL_STR};

    // res path
    std::string res_path_{NULL_STR};

    // name index
    NameIndexList name_index_list_;

    // data meta list
    DataMetaList data_meta_list_;

    // table meta list
    TableMetaList table_meta_list_;

    // container meta list
    ContainerMetaList container_meta_list_;

    // class meta call back
    std::shared_ptr<AFClassCallBackManager> class_meta_call_back_;

public:
    AFClassMeta() = delete;

    explicit AFClassMeta(const std::string& name);
    virtual ~AFClassMeta() = default;

    size_t GetNodeCount() const;
    const std::string& GetName() const;

    void SetResPath(const std::string& value);
    const std::string& GetResPath() const;

    // create data meta
    std::shared_ptr<AFNodeMeta> CreateDataMeta(const std::string& name, const uint32_t index);
    std::shared_ptr<AFNodeMeta> FindDataMeta(const uint32_t index) const;

    // create table meta
    std::shared_ptr<AFTableMeta> CreateTableMeta(const std::string& name, const uint32_t index);
    std::shared_ptr<AFTableMeta> FindTableMeta(const uint32_t index) const;

    // create table meta
    std::shared_ptr<AFContainerMeta> CreateContainerMeta(
        const std::string& name, const uint32_t index, const std::string& class_name, const ArkMaskType mask);
    std::shared_ptr<AFContainerMeta> FindContainerMeta(const uint32_t index) const;

    const DataMetaList& GetDataMetaList() const;
    const TableMetaList& GetTableMetaList() const;
    const ContainerMetaList& GetContainerMetaList() const;

    std::shared_ptr<AFClassCallBackManager> GetClassCallBackManager() const;

    uint32_t GetIndex(const std::string& name) const;

    bool IsEntityMeta() const;

private:
    bool NameIndexInsert(const std::string& name, const uint32_t index);
};

} // namespace ark
