// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.
// Author: Jan Grewe <jan.grewe@g-node.org>


#ifndef NIX_DATA_TAG_HDF5_H
#define NIX_DATA_TAG_HDF5_H

#include <string>
#include <vector>

#include <nix.hpp>
#include <nix/hdf5/EntityWithSourcesHDF5.hpp>

namespace nix {
namespace hdf5 {


class DataTagHDF5 : virtual public IDataTag, public EntityWithSourcesHDF5 {

private:

    Group representation_group;
    util::ReferenceList reference_list;

public:

    DataTagHDF5(const DataTagHDF5 &tag);


    DataTagHDF5(File file, Block block, Group group, const std::string &id);


    DataTagHDF5(File file, Block block, Group group, const std::string &id, time_t time);


    DataArray positions() const;


    void positions(const std::string &positionid);


    void positions(const DataArray &positions);


    bool hasPositions() const;


    DataArray extents() const;


    void extents(const DataArray &extents);


    void extents(const std::string &extentsId);


    bool hasExtents() const;

    //--------------------------------------------------
    // Methods concerning references.
    //--------------------------------------------------

    bool hasReference(const DataArray &reference) const;


    bool hasReference(const std::string &id) const;


    size_t referenceCount() const;


    DataArray getReference(const std::string &id) const;


    void addReference(const DataArray &reference);


    bool removeReference(const DataArray &reference);


    std::vector<DataArray> references() const;


    void references(const std::vector<DataArray> &references);

    //--------------------------------------------------
    // Methods concerning representations.
    //--------------------------------------------------


    bool hasRepresentation(const std::string &id) const;


    size_t representationCount() const;


    Representation getRepresentation(const std::string &id) const;


    Representation getRepresentation(size_t index) const;


    std::vector<Representation> representations() const;


    Representation createRepresentation(DataArray data, LinkType link_type);


    bool removeRepresentation(const std::string &id);


    template<typename T, size_t dims>
    void getReferencedData(std::vector<boost::multi_array<T, dims>> &data, size_t index) const{
        if (referenceCount() == 0){
            throw std::runtime_error("DataTagHDF5::getReferencedData: There is no reference attached to this tag!");
        }
        if(!hasPositions()){
            throw std::runtime_error("DataTagHDF5::getReferencedData: There is no positions array attached to this tag!");
        }

        DataArray pa = positions();
        boost::multi_array<double,1> posData, extData;
        pa.getRawData(posData);

        if(index >= posData.shape()[0]){
            throw std::runtime_error("DataTagHDF5::getReferencedData: index exeeds matrix dimensions in positions data!");
        }

        if(hasExtents()){
            DataArray ea = extents();
            ea.getRawData(extData);
        }

        //TODO convert position and extent to respective units
        //TODO get the data slice from the referenced DataArrays
        std::vector<DataArray> refs = references();
        for (size_t i = 0; i < refs.size();i++){

        }
    }


    //--------------------------------------------------
    // Other methods and functions
    //--------------------------------------------------


    DataTagHDF5& operator=(const DataTagHDF5 &other);


    friend std::ostream& operator<<(std::ostream &out, const DataTagHDF5 &ent);


    virtual ~DataTagHDF5();

private:

    bool checkDimensions(const DataArray &a, const DataArray &b) const;

    bool checkPositionsAndExtents() const;

};


} // namespace hdf5
} // namespace nix

#endif // NIX_DATA_TAG_HDF5_H
