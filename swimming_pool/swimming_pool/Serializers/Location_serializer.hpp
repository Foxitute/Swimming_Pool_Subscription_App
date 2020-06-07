#pragma once
#ifndef Location_serializer_hpp
#define Location_serializer_hpp
#include "Location.hpp"
#include "Serializer.hpp"

class Location_serializer : public Serializer<Location>
{
    std::string to_string(Location* entity) override;
    Location* to_object(std::string const& source) override;
};

#endif /* Location_serializer_hpp */
