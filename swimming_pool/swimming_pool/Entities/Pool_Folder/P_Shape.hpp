#pragma once
#ifndef P_Shape_hpp
#define P_Shape_hpp
#include <iostream>
#include <cmath>

#include "Shape.hpp"

class P_Shape
{
public:
    double length_, width_, depth_;
    Shapes::Shape shape_;
    
public:
    P_Shape ();
    P_Shape (double l, double w, double d, Shapes::Shape const& s);
    P_Shape (P_Shape&&);
    ~P_Shape() = default;

    void set_shape (size_t const&);
    void choice_to_shape (size_t const&);
    double calc_volume ();
    
    void set_length (double);
    void set_width  (double);
    void set_depth  (double);
    
    bool operator == (P_Shape const&);
    
private:
    P_Shape (P_Shape const&) = delete;
    P_Shape& operator = (P_Shape const&) = delete;
};

#endif /* P_Shape_hpp */
