// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

#ifndef NIX_REPRESENTATION_HDF5_H
#define NIX_REPRESENTATION_HDF5_H

#include <string>
#include <vector>

#include <nix.hpp>
#include <nix/hdf5/EntityHDF5.hpp>

namespace nix {
namespace hdf5 {


/**
 * Converts a LinkType into a string.
 *
 * @param link_type   The type to convert.
 */
std::string linkTypeToString(LinkType link_type);

/**
 * Create a link type from a string. If no matching type
 * exists, an exception will be thrown.
 *
 * @return The link type that matches the string.
 */
LinkType linkTypeFromString(const std::string &str);


/**
 * Class that represents a pandora representation entity
 */
class RepresentationHDF5 : virtual public IRepresentation, public EntityHDF5 {

private:

    Block block;

public:


    RepresentationHDF5(const RepresentationHDF5 &representation);


    RepresentationHDF5(const File &file, const Block &block, const Group &group,
                       const std::string &id);


    RepresentationHDF5(const File &file, const Block &block, const Group &group,
                       const std::string &id, time_t time);


    void linkType(LinkType type);


    LinkType linkType() const;


    void data(const DataArray &data);


    DataArray data() const;


    virtual ~RepresentationHDF5();

};


} // namespace hdf5
} // namespace nix

#endif // NIX_REPRESENTATION_HDF5_H
