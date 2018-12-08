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

#include "alexlib.h"

#include <cmath>  // std::sqrt


uint_fast32_t TriangleNumber(const uint_fast32_t& NTH) {
    /*
     * Returns the Nth triangle number. The Nth triangle number is equal to the
     * sum of all numbers from 1 to N.
     *
     * We use the closed form solution of the sum 1 to N = N * (N + 1) / 2.
     */
    return NTH * (NTH + 1) / 2;
}


bool IsPolygonal(
        const uint_fast64_t& NUMBER,
        const uint_fast32_t& MULTIPLIER,
        const double& DIVISOR
        ) {
    /*
     * A general formula for checking if a number, N, is polygonal is to check
     * if P is a natural number, with:
     *
     *     P = (Sqrt(A * N + 1) + 1) / B
     *
     * Where A is the MULTIPLIER and B is the DIVISOR. A and B are set for each
     * type of Polygonal number separately.
     */
    using std::sqrt;
    const double TEST_NUM = (sqrt(MULTIPLIER * NUMBER + 1) + 1) / DIVISOR;
    return IsPositiveInteger(TEST_NUM);
}


bool IsTriangular(const uint_fast64_t& NUMBER) {
    /*
     * For Triangular numbers, the formula is:
     *
     *     P = (Sqrt(8 * N + 1) + 1) / 2
     */
    return IsPolygonal(NUMBER, 8, 2);
}


bool IsPentagonal(const uint_fast64_t& NUMBER) {
    /*
     * For Pentagonal numbers, the formula is:
     *
     *     P = (Sqrt(24 * N + 1) + 1) / 6
     */
    return IsPolygonal(NUMBER, 24, 6);
}


bool IsHexagonal(const uint_fast64_t& NUMBER) {
    /*
     * For Hexagonal numbers, the formula is:
     *
     *     P = (Sqrt(8 * N + 1) + 1) / 4
     */
    return IsPolygonal(NUMBER, 8, 4);
}
