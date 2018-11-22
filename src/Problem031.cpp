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
 * In England the currency is made up of pound, $, and pence, p, and there are
 * eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, $1 (100p) and $2 (200p).
 *
 * It is possible to make $2 in the following way:
 *
 *     1$1 + 1*50p + 2*20p + 1*5p + 1*2p + 3*1p
 *
 * How many different ways can $2 be made using any number of coins?
 */

#include <iostream>  // std::cout, std::endl
#include <map>  // std::map
#include <vector>  // std::vector

int main() {

    // Set up constants used in the problem
    const std::vector<uint_fast8_t> COIN_VALUES = {1, 2, 5, 10, 20, 50, 100, 200};
    const uint_fast8_t MAX = 200; // pence

    /* If we want to know how many ways we can make change for a total price of
     * 4p, then using 1p coins it is equal to the number of ways we can make
     * change for 3p. For 2p as my coin it is equal to the number of ways we can
     * make change for 2p, etc. We therefore make a list of all the ways you can
     * make change for np(where n is the index) and use this to build the
     * solutions at each level.
     */

    // Fill the map
    std::map<int_fast16_t, int_fast16_t> combinations;
    for (uint_fast8_t i = 0; i <= MAX; ++i) {
        combinations[i] = 0;
    }
    combinations[0] = 1;

    for (auto& coin_value : COIN_VALUES) {
        /* We loop starting at coin_value (because anything smaller would not
         * yield a positive number) and go until we hit the target value. The
         * number of combinations at each level is incremented by the number of
         * legal ways we've found so far to make change for the current value
         * minus the value of the coin.
         */
        for (uint_fast8_t target = coin_value; target <= MAX; ++target) {
            combinations[target] += combinations[target - coin_value];
        }
    }

    std::cout << combinations[MAX] << std::endl;

    return 0;
}
