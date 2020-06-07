#pragma once
#ifndef Subscription_repository_hpp
#define Subscription_repository_hpp

#include "Repository_base.hpp"
#include "Subscription.hpp"

class Subscription_repository : public Repository_base<Subscription>
{
public:
    Subscription_repository (File_provider<Subscription>* provider, Int_id_tracker* tracker)
        : Repository_base<Subscription>(provider, tracker) {}
};

#endif /* Subscription_repository_hpp */
