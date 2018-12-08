// Copyright (C) 2018  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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

#ifndef ALEXLIB_H_
#define ALEXLIB_H_

#include <inttypes.h>  // uint_fast64_t
#include <vector>  // std::vector


bool IsPrime(const uint_fast64_t& number);

std::vector<bool>* PrimeSieve(const uint_fast64_t& LENGTH);

std::vector<uint_fast64_t>* PrimeFactors(const uint_fast64_t NUMBER);


#endif  // ALEXLIB_H_
