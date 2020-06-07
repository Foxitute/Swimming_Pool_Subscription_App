#include "Location_serializer.hpp"

/*
* Override of Serializer function for proper converting a Location object to string
*/
std::string Location_serializer::to_string(Location* entity)
{
    return std::to_string(entity->id_) + delimeter_ + entity->name;
}

/*
* Override of Serializer function for proper converting a string to Location object
*/
Location* Location_serializer::to_object(std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 2) {
        return nullptr;
    }
    
    auto locate = new Location;
    locate->id_   = std::stoi(parts[0]);
    locate->name = parts[1];
    
    return locate;
}
