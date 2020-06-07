#pragma once
#ifndef Location_hpp
#define Location_hpp

#include <string>
#include "Entity_base.hpp"

class Location : public Entity_base
{
public:
    std::string name = {};
};

#endif /* Location_hpp */
