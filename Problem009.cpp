// Copyright (C) 2010  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which, a**2 + b**2 = c**2
 *
 * For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>  // std::cout, std::endl

int main() {
    // We loop over all numbers such that a + b + c = 1000. a is already
    // determined once we have b and c.
    for (int c = 998; c > 0; c--) {
        for (int b = 1000 - c - 1; b > 0; b--) {
            const int A = 1000 - c - b;
            if (A * A + b * b == c * c) {
                std::cout << A * b * c;
                std::cout  << " = " << A << " * " << b << " * " << c;
                std::cout << std::endl;
                return 0;
            }
        }
    }

    // None found!
    return 1;
}
