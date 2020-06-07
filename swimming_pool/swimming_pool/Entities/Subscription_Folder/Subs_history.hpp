#pragma once
#ifndef Pool_subs_history_hpp
#define Pool_subs_history_hpp

#include "date_time.hpp"
#include "Entity_base.hpp"

class Subs_history : public Entity_base
{
public:
    int Pool_subscription_id = 0;
    date_time* created_at;
    int units_used = 0;
};

#endif /* Pool_subs_history_hpp */
