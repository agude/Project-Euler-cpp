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
 *
 */

#include <iostream>

int main(){

    const int MAX = 200; // pence
    int combos = 0;

    for ( int ones = 0; ones <= MAX; ones++ ) {
        int amount = ones;
        const int MAX2 = (MAX - amount) / 2;

        for ( int twos = 0; twos <= MAX2; twos++) {
            amount = ones + 2*twos;
            if (amount % 5 != 0) {
                continue;
            }
            const int MAX5 = (MAX - amount) / 5;

            for ( int fives = 0; fives <= MAX5; fives++) {
                amount = ones + 2 * twos + 5 * fives;
                if (amount % 10 != 0) {
                    continue;
                }
                const int MAX10 = (MAX - amount) / 10;

                for ( int tens = 0; tens <= MAX10; tens++) {
                    amount = ones + 2 * twos + 5 * fives + 10 * tens;
                    const int MAX20 = (MAX - amount) / 20;

                    for ( int twents = 0; twents <= MAX20; twents++) {
                        amount = ones + 2 * twos + 5 * fives + 10 * tens + 20 * twents;
                        const int MAX50 = (MAX - amount) / 50;

                        for ( int fifts = 0; fifts <= MAX50; fifts++) {
                            amount = ones + 2 * twos + 5 * fives + 10 * tens + 20 * twents + 50 * fifts;
                            const int MAX100 = (MAX - amount) / 100;

                            for ( int hunds = 0; hunds <= MAX100; hunds++) {
                                amount = ones + 2 * twos + 5 * fives + 10 * tens + 20 * twents + 50 * fifts + 100 * hunds;
                                const int MAX200 = (MAX - amount) / 200;

                                for ( int twohunds = 0; twohunds <= MAX200; twohunds++) {
                                    amount = ones + 2 * twos + 5 * fives + 10 * tens + 20 * twents + 50 * fifts + 100 * hunds + 200 * twohunds;
                                    if (amount == MAX) {
                                        combos++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << combos << std::endl;

    return 0;
}
