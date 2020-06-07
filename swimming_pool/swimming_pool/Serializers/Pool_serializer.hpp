#pragma once
#ifndef Pool_serializer_hpp
#define Pool_serializer_hpp

#include "Pool.hpp"
#include "Shape_serializer.hpp"

class Pool_serializer : public Serializer<Pool>
{
private:
    Shape_serializer* shape_serializer_;
    
public:
    Pool_serializer();
    ~Pool_serializer();
    
    std::string to_string (Pool* pool) override;
    Pool* to_object (std::string const& source) override;
};

#endif /* Pool_serializer_hpp */
