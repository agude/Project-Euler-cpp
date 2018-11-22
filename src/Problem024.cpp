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
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 *
 *     012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 */

#include <iostream>  // std::cout, std::endl
#include <vector>  // std::vector
#include <cmath>  // std::tgamma, std::round, std::floor
#include <string>


int main() {
    /*
     * We figure out the Nth number by combinatorics. We know that the first
     * (N-1)! numbers will start with 0, and then the next set of (N-1)! will
     * start with 1, and so on. This allows us to fix the first digit (that
     * is, the digit to the far left). We repeat this process for all
     * remaining numbers until we reach our goal.
     *
     */
    using std::round;
    using std::string;
    using std::tgamma;
    using std::to_string;
    // Set up the vector of digits and the target number
    std::vector<uint_fast8_t> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint_fast32_t target = 1000000 - 1;  // -1 to account for 0 indexed arrays

    string out_num = "";
    while (digits.size() > 0) {
        // The step size is (LENGTH-1)!, but since gamma(N) = (N-1)! we don't
        // need to subtract.
        const uint_fast32_t STEP_SIZE = static_cast<uint_fast32_t>(round(tgamma(digits.size())));
        const uint_fast32_t DIGIT_PLACE = target / STEP_SIZE;  // We want the floor, so integer division is fine
        // Save the digit as a string, and remove it from our list
        out_num += to_string(digits[DIGIT_PLACE]);
        const int_fast32_t DIGIT_PLACE_SIGNED = static_cast<int_fast32_t>(DIGIT_PLACE);
        digits.erase(digits.begin() + DIGIT_PLACE_SIGNED);
        // Calculate a new target number (used to determine the digit place)
        target -= DIGIT_PLACE * STEP_SIZE;
    }

    std::cout << out_num << " is the millionth lexicographic permutation of the digits 0-9." << std::endl;

    return 0;
}
