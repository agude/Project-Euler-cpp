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
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
 * number.
 *
 * A number n is called deficient if the sum of its proper divisors is less
 * than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include <iostream>  // std::cout, std::endl
#include <set>  // std::set

#include "lib/factorization.hpp"  // SumOfProperFactors

int main() {
    using std::set;

    // It is provably true that 28123 is the last number, but it can be
    // exhaustively shown that the lower bounds is actually 20161
    const int_fast16_t MAX = 20161;
    set<int_fast16_t> abundant_numbers;

    // Find abundant numbers, we keep going until we find one larger than MAX.
    // This insures that when testing our trial numbers later we know to end
    // when (trial - abundant) < 0.
    uint_fast16_t i = 0;
    while (true) {
        ++i;
        if (SumOfProperFactors(i) > i) {
            // Since the numbers are tested in order, all numbers should be
            // added to the end of the set
            abundant_numbers.emplace_hint(abundant_numbers.end(), i);
            if (i > MAX) {
                break;
            }
        }
    }

    // Check all numbers (trial) by subtracting all known abundant numbers
    // (abundant) less than that number and see if the resulting differences
    // are abundant. If none of them are, we have found a number which is not
    // the sum of two abundant numbers.
    int_fast32_t sum = 0;
    for (int_fast16_t trial = 0; trial <= MAX + 1; ++trial) {
        for (auto& abundant : abundant_numbers) {
            const int_fast16_t RESULT = trial - abundant;
            if (RESULT >= 0) {
                // If RESULT is also abundant, the trial is the sum of two
                // abundant numbers, and we don't want it.
                auto it = abundant_numbers.find(RESULT);
                if (it != abundant_numbers.end()) {
                    break;
                }
            } else if (abundant >= trial) {
                // Having gotten this far, we know (through exhaustive search)
                // that the number can not be written as the sum of abundant
                // numbers, and so is one we are interested in
                sum += trial;
                break;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
