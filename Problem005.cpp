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
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by all of the numbers
 * from 1 to 20?
 *
 */

#include <iostream>

int main() {

    long testnumber = 20 * 19;
    const int divisor[8] = {18, 17, 16, 15, 14, 13, 12, 11};
    int increment = 20 * 19;
    bool runWhile = true;

    while (runWhile) {
        for (int i = 0; i < 8; i++) {
            int d = divisor[i];

//          std::cout << d << std::endl;
            if (testnumber % d != 0) {
//              std::cout << testnumber%d << std::endl;
                testnumber += increment;
                break;
            } else if (i == 7) {
                runWhile = false;
                break;
            }
        }
    }

    std::cout << testnumber << std::endl;
    return 0;
}
