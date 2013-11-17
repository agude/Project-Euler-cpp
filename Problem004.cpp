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
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 x 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 */

#include <iostream>  // std::cout, std::endl

int Reverse(int number) {
    int reversed = 0;

    while (number > 0) {
        reversed = 10 * reversed + number % 10;
        number = number / 10;
    }

    return reversed;
}

bool IsPalindromic(const int& number) {
    return number == Reverse(number);
}

int main() {
    int palindromic = 0;
    int best_i = 0;
    int best_j = 0;

    // We try all combinations where j > i (j < i have already been tested) and
    // save the largest
    for (int i = 999; i > 100; --i) {
        for (int j = 999; j >= i; --j) {
            const int test_number = i * j;
            if (test_number > palindromic && IsPalindromic(test_number)) {
                palindromic = test_number;
                best_i = i;
                best_j = j;
            }
        }
    }

    std::cout << palindromic << " = " << best_i << " * " << best_j << std::endl;
    return 0;
}
