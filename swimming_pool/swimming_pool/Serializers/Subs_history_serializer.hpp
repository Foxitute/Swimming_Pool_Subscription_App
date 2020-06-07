#pragma once
#ifndef Pool_subs_history_serializer_hpp
#define Pool_subs_history_serializer_hpp

#include "Serializer.hpp"
#include "Subs_history.hpp"

class Subs_history_serializer : public Serializer<Subs_history>
{
public:
    std::string to_string (Subs_history* entity) override;
    Subs_history* to_object (std::string const& source) override;
};

#endif /* Pool_subs_history_serializer_hpp */
