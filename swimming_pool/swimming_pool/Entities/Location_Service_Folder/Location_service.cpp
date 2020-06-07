#include "Location_service.hpp"


Location_service::Location_service (Repository_base<Location>& repository,
                                    Repository_uow& repositories)
    : Service_base<Location>(repository, repositories) {}

/*
 * Function creates a new instance of location, sets name of the location
 *                     and passes the instance to the location repository
 */
void Location_service::create_location (std::string name) const
{
    auto new_location = new Location;
    new_location->name = std::move(name);
    
    repository_.add(new_location);
}
