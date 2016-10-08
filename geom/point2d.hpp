/* ==================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/geom
 * ================================================== */

#ifndef GEOM_POINT2D_HPP
#define GEOM_POINT2D_HPP

#include <cstdlib>
#include <geom/util.hpp>

namespace geom {

/*! @brief 二次元の座標値を表すクラス */
template <class T>
class point2d {
  public:
    point2d()
        : x_coord_(static_cast<T>(0))
        , y_coord_(static_cast<T>(0))
    {
    }

    point2d(T x_coord, T y_coord)
        : x_coord_(x_coord)
        , y_coord_(y_coord)
    {
    }

    point2d(const point2d& other)
        : x_coord_(other.x_coord_)
        , y_coord_(other.y_coord_)
    {
    }
    
    T x() const { return x_coord_; }
    T y() const { return y_coord_; }
    
    void set_x(T x_coord) { x_coord_ = x_coord; }
    void set_y(T y_coord) { y_coord_ = y_coord; }

    T& rx() { return x_coord_; }
    T& ry() { return y_coord_; }

    const T& rx() const { return x_coord_; }
    const T& ry() const { return y_coord_; }

    bool is_null() const {
        return (equals(x_coord_, static_cast<T>(0)) &&
                equals(y_coord_, static_cast<T>(0)));
    }

    T manhattan_length() const {
        return std::abs(x_coord_) + std::abs(y_coord_);
    }

    point2d<T>& operator = (const point2d<T>& other) {
        x_coord_ = other.x_coord_;
        y_coord_ = other.y_coord_;
        return *this;
    }
    
    point2d<T>& operator += (const point2d<T>& other) {
        x_coord_ += other.x_coord_;
        y_coord_ += other.y_coord_;
        return *this;
    }

    point2d<T>& operator -= (const point2d<T>& other) {
        x_coord_ -= other.x_coord_;
        y_coord_ -= other.y_coord_;
        return *this;
    }

    point2d<T>& operator *= (T factor) {
        x_coord_ *= factor;
        y_coord_ *= factor;
        return *this;
    }

    point2d<T>& operator /= (T divisor) {
        x_coord_ /= divisor;
        y_coord_ /= divisor;
        return *this;
    }

    friend
    point2d<T> operator + (point2d<T> lhs, const point2d<T>& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend
    point2d<T> operator - (point2d<T> lhs, const point2d<T>& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend
    point2d<T> operator * (point2d<T> lhs, T rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend
    point2d<T> operator * (T lhs, point2d<T> rhs) {
        rhs *= lhs;
        return rhs;
    }

    friend
    point2d<T> operator / (point2d<T> lhs, T rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend
    bool operator == (const point2d<T>& lhs, const point2d<T>& rhs) {
        return (equals(lhs.x_coord_, rhs.x_coord_) &&
                equals(lhs.y_coord_, rhs.y_coord_));
    }

    friend
    bool operator != (const point2d<T>& lhs, const point2d<T>& rhs) {
        return !(lhs == rhs);
    }

    friend // for std::map
    bool operator < (const point2d<T>& lhs, const point2d<T>& rhs) {
        if (lhs.x_coord_ < rhs.x_coord_) return true;
        if (lhs.x_coord_ > rhs.x_coord_) return false;
        if (lhs.y_coord_ < rhs.y_coord_) return true;
        if (lhs.y_coord_ > rhs.y_coord_) return false;
        return false;
    }

  private:
    T x_coord_;
    T y_coord_;
};


} // namespace geom

#endif // GEOM_POINT2D_HPP
