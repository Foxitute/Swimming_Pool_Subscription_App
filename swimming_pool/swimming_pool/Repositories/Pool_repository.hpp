#pragma once
#ifndef Pool_repository_hpp
#define Pool_repository_hpp
#include "Repository_base.hpp"
#include "Pool.hpp"

class Pool_repository : public Repository_base<Pool>
{
public:
    Pool_repository (File_provider<Pool>* provider, Int_id_tracker* tracker);
    
    Pool* get_by_number (std::string const& number) const;
};

#endif /* Pool_repository_hpp */
