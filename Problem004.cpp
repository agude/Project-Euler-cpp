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

#include <iostream>

const long reverse(long num){

    long reversed = 0;
    while( num > 0 ){
        reversed = 10*reversed + num%10;
        num = num/10;
    }
    return reversed;
}

const bool isPalindromic(const long num){
    const long reversed = reverse(num);
    if( num == reversed ){
        return true;
    }
    return false;
}

int main(){

    long Palindromic = 0;

    for(int i = 999; i > 100; i--){
        for(int j = i; j < 1000; j++){

            const long testNum = i*j;

            if( testNum > Palindromic ){
                if( isPalindromic(testNum) ){
                    Palindromic = testNum;
                }
            }

        }
    }

    std::cout << Palindromic << std::endl;
    return 0;
}

