#pragma once
#ifndef Pool_subscription_serializer_hpp
#define Pool_subscription_serializer_hpp

#include "Serializer.hpp"
#include "Pool_subscription.hpp"

class Pool_subscription_serializer : public Serializer<Pool_subscription>
{
public:
    std::string to_string(Pool_subscription* entity) override;
    Pool_subscription* to_object(std::string const& source) override;
};

#endif /* Pool_subscription_serializer_hpp */
