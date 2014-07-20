// Copyright (C) 2014  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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

/*
 * If p is the perimeter of a right angle triangle with integral length sides, {a, b, c},
 * there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 */

#include <iostream>  // std::cout, std::endl
#include <cmath>  // std::trunc, sqrt
#include <algorithm>  // std::min

int main() {

    // Set up constants used in the problem
    const int MAX = 1000;

    /* We note that are three cases:
     *  a even, b even -> c even -> p even
     *  a odd,  b odd  -> c even -> p even
     *  a even, b odd  -> c odd  -> p even

     * So we need only check even parameters

     * We further note that the triangle inequality holds:
     *  a + b > c --> a + b + c > 2c --> p > 2c --> p/2 > c
     *  c > a or b, hence p / 2 > c or a or b
     *  So a and be need only run up to p/2
     */

    int best_combos = 0;
    int best_parameter = 0;
    for (int parameter = 12; parameter <= MAX; parameter += 2) {
        int combos = 0;
        for (int a = 1; a < parameter / 2; ++a) {
            // b + a can't be larger than parameter, and b can't be larger than
            // half the parameter, so the limit on b is the minimum of these two
            const int MAX_B = std::min(parameter - a, parameter / 2);
            for (int b = 1; b < MAX_B; ++b) {
                double c = sqrt(a * a + b * b);
                if (a + b + c == parameter) {
                    // Check that c is integral
                    if (trunc(c) == c) {
                        ++combos;
                    }
                }
            }
        }

        // Check if we have a new best parameter value
        if (combos > best_combos) {
            best_combos = combos;
            best_parameter = parameter;
        }
    }

    std::cout << best_parameter << std::endl;

    return 0;
}
