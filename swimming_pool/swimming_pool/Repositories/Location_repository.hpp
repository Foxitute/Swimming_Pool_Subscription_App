#pragma once
#ifndef Location_repository_hpp
#define Location_repository_hpp

#include "Location.hpp"
#include "Repository_base.hpp"

class Location_repository : public Repository_base<Location>
{
public:
    explicit Location_repository (File_provider<Location>* provider, Int_id_tracker* tracker)
        : Repository_base<Location>(provider, tracker) {}
};

#endif /* Location_repository_hpp */
