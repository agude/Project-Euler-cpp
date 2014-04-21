// Copyright (C) 2013  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef ALEXLIB_TCC_
#define ALEXLIB_TCC_

#include <cmath>  // std::sqrt, std::floor, std::abs, std::ceil, std::modf
#include <numeric>  // std::accumulate
#include <vector>  // std::vector


template <class T>
std::vector<T>* Factors(const T& NUMBER) {
    using std::floor;
    using std::sqrt;
    using std::vector;

    // Vector to return
    vector<T>* factors = new vector<T>();

    const T MAX = static_cast<int>(floor(sqrt(NUMBER)));

    for (T i = 1; i <= MAX; ++i) {
        if (NUMBER % i == 0) {
            const T FACTOR_0 = i;
            const T FACTOR_1 = NUMBER / i;

            if (FACTOR_0 == FACTOR_1) {
                factors->push_back(FACTOR_0);
            } else {
                factors->push_back(FACTOR_0);
                factors->push_back(FACTOR_1);
            }
        }
    }
    return factors;
}

template <class T>
T NumberOfFactors(const T& NUMBER) {
    using std::vector;
    /*
     * Given a number, returns the number of factors.
     */
    vector<T> const * const FACTORS = Factors(NUMBER);
    return static_cast<T>(FACTORS->size());
}

template <class T>
T NumberOfProperFactors(const T& NUMBER) {
    /*
     * Given a number, returns the number of proper factors.
     */
    return NumberOfFactors(NUMBER) - 1;
}

template <class T>
T SumOfFactors(const T& NUMBER) {
    using std::accumulate;
    using std::vector;
    /*
     * Given a number, returns the number of factors.
     */
    vector<T> const * const FACTORS = Factors(NUMBER);
    const T INITIAL_VALUE = 0;
    return accumulate(FACTORS->begin(), FACTORS->end(), INITIAL_VALUE);
}

template <class T>
T SumOfProperFactors(const T& NUMBER) {
    /*
     * Given a number, returns the sum of proper factors, that is all the
     * factors except for the number itself.
     */
    return SumOfFactors(NUMBER) - NUMBER;
}


template <class T>
bool IsInteger(const T& NUMBER) {
    /*
     * Returns "true" if NUMBER is an integer (..., -2, -1, 0, 1, 2, ...),
     * "false" otherwise.
     */
    using std::modf;
    double int_part = 0;
    double decimal_part = 0;
    // modf splits a.b into a, and 0.b
    decimal_part = modf(NUMBER, &int_part);
    return (decimal_part == 0);
}

template <class T>
bool IsPositiveInteger(const T& NUMBER) {
    /*
     * Returns "true" if NUMBER is a positive integer (1, 2, 3, ...), "false"
     * otherwise.
     */
    return (NUMBER >= 1 && IsInteger(NUMBER));
}

template <class T>
bool IsNonNegativeInteger(const T& NUMBER) {
    /*
     * Returns "true" if NUMBER is a nonnegative integer (0, 1, 2, 3, ...),
     * "false" otherwise.
     */
    return (NUMBER >= 0 && IsInteger(NUMBER));
}

template <class T>
bool IsNonPositiveInteger(const T& NUMBER) {
    /*
     * Returns "true" if NUMBER is a nonpositive integer (0, -1, -2, -3, ...),
     * "false" otherwise.
     */
    return (NUMBER <= 0 && IsInteger(NUMBER));
}

template <class T>
bool IsNegativeInteger(const T& NUMBER) {
    /*
     * Returns "true" if NUMBER is a negative integer (-1, -2, -3, ...),
     * "false" otherwise.
     */
    return (NUMBER <= -1 && IsInteger(NUMBER));
}

#endif  // ALEXLIB_TCC_
