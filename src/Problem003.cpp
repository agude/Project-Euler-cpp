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

/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */

#include <iostream>  // std::cout, std::endl
#include <inttypes.h>  // int64_t

#include "lib/alexlib.h"  // PrimeFactors


int main() {
    using std::vector;
    using std::cout;
    using std::endl;

    const int64_t NUMBER = 600851475143;

    // We find all the prime factors, then the largest is the final one
    vector<int64_t> const * const PRIME_FACTORS = PrimeFactors(NUMBER);

    cout << PRIME_FACTORS->back() << endl;
    return 0;
}
