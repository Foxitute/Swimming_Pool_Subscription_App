#pragma once
#ifndef Pool_subscription_repository_hpp
#define Pool_subscription_repository_hpp

#include "Pool_subscription.hpp"
#include "Repository_base.hpp"

class Pool_subscription_repository : public Repository_base<Pool_subscription>
{
public:
    explicit Pool_subscription_repository (File_provider<Pool_subscription>* provider, Int_id_tracker* tracker)
        : Repository_base(provider, tracker) {}
};

#endif /* Pool_subscription_repository_hpp */
