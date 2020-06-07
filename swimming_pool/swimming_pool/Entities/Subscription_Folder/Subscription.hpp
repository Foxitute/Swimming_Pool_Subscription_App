#pragma once
#ifndef Subscription_hpp
#define Subscription_hpp

#include "date_time.hpp"
#include "Entity_base.hpp"

class Subscription : public Entity_base
{
public:
    std::string name = {};
    std::string type = {};
    std::string unit_title = {};
    int hours = 0;
    int max_unit_count = 0;
    date_time* effective_from = nullptr;
    date_time* effective_to   = nullptr;
};

#endif /* Subscription_hpp */
