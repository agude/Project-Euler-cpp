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

#include <cmath>  // std::sqrt, std::floor, std::abs, std::ceil
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

    for (T i = 1; i < MAX + 2; i++) {
        if (NUMBER % i == 0) {
            const T f1 = i;
            const T f2 = NUMBER / i;

            if (f1 == f2) {
                factors->push_back(f1);
            } else {
                factors->push_back(f1);
                factors->push_back(f2);
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

#endif  // ALEXLIB_TCC_
