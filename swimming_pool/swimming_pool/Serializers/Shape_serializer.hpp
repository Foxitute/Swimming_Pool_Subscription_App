#pragma once
#ifndef Shape_serializer_hpp
#define Shape_serializer_hpp

#include "Serializer.hpp"
#include "P_Shape.hpp"

class Shape_serializer : public Serializer<P_Shape>
{
public:
    virtual std::string to_string (P_Shape* shape) override;

    virtual P_Shape* to_object(std::string const& source) override;
};
#endif /* Shape_serializer_hpp */
