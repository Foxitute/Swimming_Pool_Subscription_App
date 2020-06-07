#pragma once
#ifndef Service_base_hpp
#define Service_base_hpp

#include "Repository_base.hpp"
#include "Repository_uow.hpp"

template <typename T> class Service_base
{
protected:
    Repository_base<T>& repository_;
    Repository_uow& repositories_;
    
    Service_base (Repository_base<T>& repository, Repository_uow& repositories)
        : repository_(repository), repositories_(repositories) {}
};

#endif /* Service_base_hpp */
