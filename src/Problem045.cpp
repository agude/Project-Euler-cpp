// Copyright (C) 2011  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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
 * Triangle, pentagonal, and hexagonal numbers are generated by the following
 * formulae:
 *
 * Triangle        Tn = n(n+1)/2      1, 3, 6, 10, 15, ...
 * Pentagonal      Pn = n(3n-1)/2     1, 5, 12, 22, 35, ...
 * Hexagonal       Hn = n(2n-1)       1, 6, 15, 28, 45, ...
 *
 * It can be verified that T285 = P165 = H143 = 40755.
 *
 * Find the next triangle number that is also pentagonal and hexagonal.
 */

#include <iostream>  // std::cout, std::endl
#include <inttypes.h>  // int64_t

#include "lib/alexlib.h"  // IsPentagonal


int main() {
    /*
     * We generate the hexagonal numbers using the formula provided: n*(2*n-1)
     * We then check if they are pentagonal, but we do not check if they are
     * triangular as all hexagonal numbers are by definition. We generate
     * hexagonal numbers because there are fewer of them, and therefore we have
     * to check fewer numbers before finding the correct result.
     */
    int n = 144; // H143 satisfies the conditions, so we start after
    int64_t num = 0;

    // Try hexagonal numbers until we find a match
    while (true) {
        num = n * (2 * n - 1);
        // If it is also pentagonal, we're done
        if (IsPentagonal(num)) {
            break;
        } else {
            ++n;
        }
    }

    std::cout << "H" << n << " = " << num;
    std::cout << " is pentagonal and triangular." << std::endl;

    return 0;
}
