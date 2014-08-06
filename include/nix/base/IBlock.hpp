// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

#ifndef NIX_I_BLOCK_H
#define NIX_I_BLOCK_H

#include <string>
#include <vector>

#include <nix/base/IEntityWithMetadata.hpp>
#include <nix/base/ISource.hpp>
#include <nix/base/IDataArray.hpp>
#include <nix/base/ISimpleTag.hpp>
#include <nix/base/IDataTag.hpp>
#include <nix/NDSize.hpp>

namespace nix {
namespace base {

/**
 * @brief Interface for implementations of the Block entity.
 *
 * See {@link nix::Block} for a more detailed description.
 */
class NIXAPI IBlock : virtual public base::IEntityWithMetadata {

public:


    virtual bool hasSource(const std::string &id) const = 0;


    virtual std::shared_ptr<base::ISource> getSource(const std::string &id) const = 0;


    virtual std::shared_ptr<base::ISource> getSource(size_t index) const = 0;


    virtual size_t sourceCount() const = 0;


    virtual std::shared_ptr<base::ISource> createSource(const std::string &name, const std::string &type) = 0;


    virtual bool deleteSource(const std::string &id) = 0;

    //--------------------------------------------------
    // Methods concerning data arrays
    //--------------------------------------------------

    virtual bool hasDataArray(const std::string &id) const = 0;


    virtual std::shared_ptr<base::IDataArray> getDataArray(const std::string &id) const = 0;


    virtual std::shared_ptr<base::IDataArray> getDataArray(size_t index) const = 0;


    virtual size_t dataArrayCount() const = 0;


    virtual std::shared_ptr<base::IDataArray> createDataArray(const std::string &name, const std::string &type,
                                                              nix::DataType data_type, const NDSize &shape) = 0;


    virtual bool deleteDataArray(const std::string &id) = 0;

    //--------------------------------------------------
    // Methods concerning simple tags.
    //--------------------------------------------------

    virtual bool hasSimpleTag(const std::string &id) const = 0;


    virtual std::shared_ptr<base::ISimpleTag> getSimpleTag(const std::string &id) const = 0;


    virtual std::shared_ptr<base::ISimpleTag> getSimpleTag(size_t index) const = 0;


    virtual size_t simpleTagCount() const = 0;

    // TODO evaluate if DataArray can be replaced by shared_ptr<IDataArray>
    virtual std::shared_ptr<base::ISimpleTag> createSimpleTag(const std::string &name, const std::string &type,
                                                              const std::vector<double> &position) = 0;


    virtual bool deleteSimpleTag(const std::string &id) = 0;

    //--------------------------------------------------
    // Methods concerning data tags.
    //--------------------------------------------------

    virtual bool hasDataTag(const std::string &id) const = 0;


    virtual std::shared_ptr<base::IDataTag> getDataTag(const std::string &id) const = 0;


    virtual std::shared_ptr<base::IDataTag> getDataTag(size_t index) const = 0;


    virtual size_t dataTagCount() const = 0;


    // TODO evaluate if DataArray can be replaced by shared_ptr<IDataArray>
    virtual std::shared_ptr<base::IDataTag> createDataTag(const std::string &name, const std::string &type,
                                                          const DataArray &positions) = 0;


    virtual bool deleteDataTag(const std::string &id) = 0;


    virtual ~IBlock() {}

};

} // namespace base
} // namespace nix


#endif // NIX_I_BLOCK_H
