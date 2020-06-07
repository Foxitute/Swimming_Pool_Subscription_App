#pragma once
#ifndef Pool_hpp
#define Pool_hpp

#include "P_Shape.hpp"
#include "Entity_base.hpp"

class Pool : public Entity_base
{
public:
    std::string serial_number_ = {};
    P_Shape* pshape_;
    
public:
    Pool () = default;
    Pool (std::string const&, P_Shape*);
    Pool (Pool&&);
    ~Pool() = default;
    
private:
    Pool (Pool const&) = delete;
    Pool& operator = (Pool const&) = delete;
};

#endif /* Pool_hpp */
