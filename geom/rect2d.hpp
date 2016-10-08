/* ==================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/geom
 * ================================================== */

#ifndef GEOM_RECT2D_HPP
#define GEOM_RECT2D_HPP

#include <geom/line2d.hpp>
#include <geom/size2d.hpp>
#include <geom/point2d.hpp>
#include <geom/util.hpp>

namespace geom {

template <class T>
class rect2d {
  public:
    rect2d()
        : top_left_point_()
        , bottom_right_point_()
    {
    }

    rect2d(const point2d<T>& top_left_point,
           const point2d<T>& bottom_right_point)
        : top_left_point_(top_left_point)
        , bottom_right_point_(bottom_right_point)
    {
    }

    rect2d(const point2d<T>& top_left_point,
           const size2d<T>& size)
            : top_left_point_(top_left_point)
            , bottom_right_point_(point2d<T>(
                top_left_point.x() + size.width(),
                top_left_point.y() + size.height()))
    {
    }

    rect2d(T x, T y, T width, T height)
        : top_left_point_(point2d<T>(x, y))
        , bottom_right_point_(point2d<T>(
            x + width, y + height))
    {
    }

    void adjust(T dx1, T dy1, T dx2, T dy2) {
        top_left_point_ += point2d<T>(dx1, dy1);
        bottom_right_point_ += point2d<T>(dx2, dy2);
    }

    T bottom() const {
        return bottom_right_point_.y();
    }

    point2d<T> bottom_left() const {
        return point2d<T>(
            top_left_point_.x(), bottom_right_point_.y());
    }

    point2d<T> bottom_right() const {
        return bottom_right_point_;
    }

    T top() const {
        return top_left_point_.y();
    }

    point2d<T> top_left() const {
        return top_left_point;
    }

    point2d<T> top_right() const {
        return point2d<T>(
            bottom_right_point_.x(), top_left_point_.y());
    }

    point2d<T> center() const {
        return point2d<T>(
            (top_left_point_.x() + bottom_right_point_.x()) / static_cast<T>(2),
            (top_left_point_.y() + bottom_right_point_.y()) / static_cast<T>(2));
    }

    bool contains
    (const point2d<T>& point, bool proper = false) const {
        if (proper) 
            return (greater(point.x(), top_left_point_.x()) &&
                    greater(point.y(), top_left_point_.y()) &&
                    less(point.x(), bottom_right_point_.x()) &&
                    less(point.y(), bottom_right_point_.y()));
        else 
            return (greater_equals(point.x(), top_left_point_.x()) &&
                    greater_equals(point.y(), top_left_point_.y()) &&
                    less_equals(point.x(), bottom_right_point_.x()) &&
                    less_equals(point.y(), bottom_right_point_.y()));
    }

    bool contains(T x, T y, bool proper = false) const {
        point2d<T> p(x, y);
        return contains(p, proper);
    }

    bool contains(const rect2d<T>& rectangle) const {
        return (contains(rectangle.top_left_point_) &&
                contains(rectangle.bottom_right_point_));
    }

    
  private:
    point2d<T> top_left_point_;
    point2d<T> bottom_right_point_;
};

} // namespace geom

#endif // GEOM_RECT2D_HPP
