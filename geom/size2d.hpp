/* ==================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/geom
 * ================================================== */

#ifndef GEOM_SIZE2D_HPP
#define GEOM_SIZE2D_HPP

#include <algorithm>

namespace geom {

template <class T>
class size2d {
  public:
    size2d()
        : width_(static_cast<T>(0))
        , height_(static_cast<T>(0))
    {
    }

    size2d(T width, T height)
        : width_(width)
        , height_(height)
    {
    }

    size2d(const size2d<T>& other)
        : width_(other.width_)
        , height_(other.height_)
    {
    }

    size2d<T> bounded_to(const size2d<T>& other_size) const {
        return size2d<T>(
            std::min(width_, other_size.width_),
            std::min(height_, other_size.height_));
    }

    size2d<T> expanded_to(const size2d<T>& other_size) const {
        return size2d<T>(
            std::max(width_, other_size.width_),
            std::max(height_, other_size.height_));
    }

    T width() const { return width_; }
    T height() const { return height_; }

    void set_width(T width) { width_ = width; }
    void set_height(T height) { height_ = height; }

    T& rwidth() { return width_; }
    T& rheight() { return height_; }
    const T& rwidth() const { return width_; }
    const T& rheight() const { return height_; }

  private:
    T width_;
    T height_;
};

} // namespace geom

#endif // GEOM_SIZE2D_HPP
