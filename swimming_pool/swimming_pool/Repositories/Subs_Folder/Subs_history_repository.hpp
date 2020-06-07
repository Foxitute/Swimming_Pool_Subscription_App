#pragma once
#ifndef Subs_history_repository_hpp
#define Subs_history_repository_hpp

#include "Repository_base.hpp"
#include "Subs_history.hpp"

class Subs_history_repository : public Repository_base<Subs_history>
{
public:
    explicit Subs_history_repository (File_provider<Subs_history>* provider, Int_id_tracker* tracker)
        : Repository_base<Subs_history>(provider, tracker) {}
};

#endif /* Subs_history_repository_hpp */
