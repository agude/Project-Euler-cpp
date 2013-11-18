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

#include <math.h>  // sqrt, floor

int NumberOfFactors(const int& NUMBER) {
    /*
     * Given a number, returns the number of factors.
     */
    int number_of_factors = 0;

    const float fnum = (float)NUMBER;
    const int MAX  = (int)floor(sqrt(fnum));

    for (int i = 1; i < MAX + 2; i++) {
        if (NUMBER % i == 0) {
            const int f1 = i;
            const int f2 = NUMBER / i;

            if (f1 == f2) {
                number_of_factors += 1;
            } else {
                number_of_factors += 2;
            }
        }
    }
    return number_of_factors;
}

int TriangleNumber(const int& NTH) {
    /*
     * Returns the Nth triangle number. The Nth triangle number is equal to the
     * sum of all numbers from 1 to N.
     *
     * We use the closed form solution of the sum 1 to N = N * (N + 1) / 2.
     */
    return NTH * (NTH + 1) / 2;
}
