/* ==================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/geom
 * ================================================== */

#ifndef GEOM_UTIL_HPP
#define GEOM_UTIL_HPP

#include <limits>
#include <type_traits>
#include <cmath>

namespace geom {

template <class T>
bool fuzzy_equals(T lhs, T rhs) {
    static_assert(std::is_floating_point<T>::value == true &&
                  std::is_floating_point<T>::value == true,
                  "Arguments must be floating point number");
    T max = std::max(std::abs(lhs), std::abs(rhs));
    return std::abs(lhs - rhs) <= std::numeric_limits<T>::epsilon() * max;
}

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
equals(T lhs, T rhs) {
    return fuzzy_equals(lhs, rhs);
}

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
equals(T lhs, T rhs) {
    return lhs == rhs;
}

template <class T>
bool greater(T lhs, T rhs) {
    return lhs > rhs;
}

template <class T>
bool less(T lhs, T rhs) {
    return lhs < rhs;
}

template <class T>
bool greater_equals(T lhs, T rhs) {
    return greater(lhs, rhs) || equals(lhs, rhs);
}

template <class T>
bool less_equals(T lhs, T rhs) {
    return less(lhs, rhs) || equals(lhs, rhs);
}

} // namespace geom

#endif // GEOM_UTIL_HPP

