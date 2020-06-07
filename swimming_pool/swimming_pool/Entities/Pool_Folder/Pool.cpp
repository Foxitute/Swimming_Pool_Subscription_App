#include "Pool.hpp"

Pool::Pool (std::string const& number, P_Shape* shape)
    : serial_number_(number), pshape_(shape) { }

Pool::Pool (Pool&& other)
    : serial_number_(std::move(other.serial_number_))
    , pshape_(std::move(other.pshape_)) { }
