#pragma once
#ifndef Location_service_hpp
#define Location_service_hpp

#include "Service_base.hpp"

class Location_service : public Service_base<Location>
{
public:
    Location_service (Repository_base<Location>& repository,
                      Repository_uow& repositories);

    void create_location (std::string name) const;
};

#endif /* Location_service_hpp */
