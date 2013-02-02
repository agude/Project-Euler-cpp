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

// The most recent version of this program is available at:
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * The sum of the squares of the first ten natural numbers is, 
 * 1**2 + 2**2 + ... + 10**2 = 385
 *
 * The square of the sum of the first ten natural numbers is, 
 * (1 + 2 + ... + 10)**2 = 55**2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 - 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 *
 */

#include <iostream>

int main(){
    long sumOfSqr = 0;
    long sum = 0;
    long sqrOfSum = 0;
    long answer = 0;

    for(int i; i < 101; i++){
        sumOfSqr += i*i;
        sum += i;
}
    sqrOfSum = sum*sum;
    answer = sqrOfSum - sumOfSqr;
    
    std::cout << answer << std::endl;

    return 0;
}
