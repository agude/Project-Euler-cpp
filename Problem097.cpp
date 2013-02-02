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
 * The first known prime found to exceed one million digits was discovered in
 * 1999, and is a Mersenne prime of the form 269725931; it contains exactly
 * 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p1, have
 * been found which contain more digits.
 *
 * However, in 2004 there was found a massive non-Mersenne prime which contains
 * 2,357,207 digits: 2843327830457+1.
 *
 * Find the last ten digits of this prime number.
 *
 */

#include <iostream>
#include <math.h>

int main(){

    std::cout << ((28433*(pow(2,7830457)))+1)%10000000000 << std::endl;

    return 0;
}
