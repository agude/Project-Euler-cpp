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
 * The following iterative sequence is defined for the set of positive
 * integers:
 *
 * n --> n/2 (n is even)
 * n --> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence: 13 --> 40 --> 20 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>  // std::cout, std::endl

uint_fast32_t ChainLength(uint_fast32_t number) {
    uint_fast32_t chain_length = 1;

    // If number is even, n --> n/2;
    // else n --> 3n+1
    while (number > 1) {
        chain_length++;
        if (number % 2 == 0) {
            number = number / 2;
        }
        else {
            number = 3 * number + 1;
        }
    }
    return chain_length;
}

int main() {
    uint_fast32_t longest_chain = 0;
    uint_fast32_t longest_start = 0;

    // Try all numbers
    for (uint_fast32_t i = 1; i < 1000000; i++) {
        uint_fast32_t chain_length = ChainLength(i);

        if (chain_length > longest_chain) {
            longest_chain = chain_length;
            longest_start = i;
        }
    }

    std::cout << longest_start << " with length " << longest_chain << std::endl;
    return 0;
}
