#include "P_Shape.hpp"

P_Shape::P_Shape(double length, double width, double depth, Shapes::Shape const& shape)
    : length_(length), width_(width), depth_(depth), shape_(shape) {}

P_Shape::P_Shape() : P_Shape(0,0,0,Shapes::Undefined) {}

P_Shape::P_Shape(P_Shape&& other)
    : length_(std::move(other.length_))
    , width_ (std::move(other.width_))
    , depth_ (std::move(other.depth_))
    , shape_ (std::move(other.shape_)) {}

void P_Shape::choice_to_shape(size_t const& choice)
{
    using namespace Shapes;
    shape_ = (choice == 1 ? Round :
              choice == 2 ? Rectangle :
              choice == 3 ? Square : Undefined);
    if (shape_ == Undefined)
        throw std::runtime_error("Undefined Shape!!! in choice_to_shape function");
}

double P_Shape::calc_volume()
{
    using namespace Shapes;
    if (shape_ == Round)
        return 2 * M_PI * pow((length_/2.), 2.) * depth_;
    else if (shape_ == Rectangle)
        return length_ * width_ * depth_;
    else if (shape_ == Square)
        return pow(length_, 2.) * depth_;
    
    throw std::runtime_error("Undefined Shape!!! in calc_volume function");
}

void P_Shape::set_length(double length){ length_= length; }
void P_Shape::set_width (double width) { width_ = width;  }
void P_Shape::set_depth (double depth) { depth_ = depth;  }

bool P_Shape::operator == (P_Shape const& p_shape)
{
    return (length_ == p_shape.length_ &&
            width_  == p_shape.width_  &&
            depth_  == p_shape.depth_  &&
            shape_  == p_shape.shape_  );
}
