#pragma once
#ifndef Pool_subscription_hpp
#define Pool_subscription_hpp

#include "date_time.hpp"
#include "Entity_base.hpp"

class Pool_subscription : public Entity_base
{
public:
    int pool_id = 0;
    int subscription_id = 0;
    int unit_count = 0;
    date_time* created_at = nullptr;
    date_time* effective_from = nullptr;
    date_time* effective_to = nullptr;
};

#endif /* Pool_subscription_hpp */
