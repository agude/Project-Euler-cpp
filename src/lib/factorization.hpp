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

#ifndef FACTORSLIB_TCC_
#define FACTORSLIB_TCC_

#include <cmath>  // std::sqrt, std::floor
#include <numeric>  // std::accumulate
#include <vector>  // std::vector


template <class T>
std::vector<T>* Factors(const T& NUMBER) {
    using std::floor;
    using std::sqrt;
    using std::vector;

    // Vector to return
    vector<T>* factors = new vector<T>();

    const T MAX = static_cast<T>(floor(sqrt(NUMBER)));

    for (T i = 1; i <= MAX; ++i) {
        if (NUMBER % i == 0) {
            const T FACTOR_0 = i;
            const T FACTOR_1 = NUMBER / i;

            if (FACTOR_0 == FACTOR_1) {
                factors->push_back(FACTOR_0);
            }
            else {
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
    vector<T> const* const FACTORS = Factors(NUMBER);
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
    vector<T> const* const FACTORS = Factors(NUMBER);
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


#endif  // FACTORSLIB_TCC_
