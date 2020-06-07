#pragma once
#ifndef Subscription_serializer_hpp
#define Subscription_serializer_hpp

#include "Serializer.hpp"
#include "Subscription.hpp"

class Subscription_serializer : public Serializer<Subscription>
{
    std::string to_string(Subscription* entity) override;
    Subscription* to_object(std::string const& source) override;
};

#endif /* Subscription_serializer_hpp */
