/* ==================================================
 * Copyright (c) 2016 tacigar. All rights reserved
 * https://github.com/tacigar/geom
 * ================================================== */

#ifndef GEOM_LINE2D_HPP
#define GEOM_LINE2D_HPP

#include <cstdlib>
#include <geom/point2d.hpp>

namespace geom {

/*! @brief 二次元での線を表現するクラス */
template <class T>
class line2d {
  public:
    line2d()
        : point1_()
        , point2_()
    {
    }

    lint2d(const point2d<T>& point1,
           const point2d<T>& point2)
        : point1_(point1)
        , point2_(point2)
    {
    }

    lint2d(T x1, T y1, T x2, T y2)
        : point1_(point2d<T>(x1, y1))
        , point2_(point2d<T>(x2, y2))
    {
    }

    point2d<T> point1() const {
        return point1_;
    }

    point2d<T> point2() const {
        return point2_;
    }

    void set_point1(const point2d<T>& point1) {
        point1_ = point1;
    }

    void set_point2(const point2d<T>& point2) {
        point2_ = point2;
    }

    T x1() const { return point1_.x(); }
    T y1() const { return point1_.y(); }
    T x2() const { return point2_.x(); }
    T y2() const { return point2_.y(); }

    T dx() const { return std::abs(point1_.x() - point2_.x()); }
    T dy() const { return std::abs(point1_.y() - point2_.y()); }

    bool is_null() const {
        return point1_.is_null() && point2_.is_null();
    }

    void set_line(T x1, T y1, T x2, T y2) {
        point1_ = point2d<T>(x1, y1);
        point2_ = point2d<T>(x2, y2);
    }

    void set_points(const point2d<T>& point1,
                    const point2d<T>& point2) {
        point1_ = point1;
        point2_ = point2;
    }

    void translate(const point2d<T>& offset) {
        point1_ += offset;
        point2_ += offset;
    }

    void translate(T dx, T dy) {
        point2d<T> offset(dx, dy);
        translate(offset);
    }

    friend 
    bool operator == (const line2d<T>& lhs, const line2d<T>& rhs) {
        return (lhs.point1_ == rhs.point1_ &&
                lhs.point2_ == rhs.point2_);
    }

    friend
    bool operator != (const line2d<T>& lhs, const line2d<T>& rhs) {
        return !(lhs == rhs);
    }
    
  private:
    point2d<T> point1_;
    point2d<T> point2_;
};

} // namespace geom

#endif // GEOM_LINE2D_HPP
