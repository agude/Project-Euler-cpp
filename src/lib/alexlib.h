// Copyright (C) 2013  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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

#include <inttypes.h>  // int64_t
#include <vector>  // std::vector


int TriangleNumber(const int& NTH);

bool IsPrime(const int64_t& number);

std::vector<bool>* PrimeSieve(const int64_t& LENGTH);

std::vector<int64_t>* PrimeFactors(const int64_t NUMBER);

bool IsPolygonal(
        const int64_t& NUMBER,
        const int& MULTIPLIER,
        const double& DIVISOR
        );

bool IsTriangular(const int64_t& NUMBER);

bool IsPentagonal(const int64_t& NUMBER);

bool IsHexagonal(const int64_t& NUMBER);

template <class T>
std::vector<T>* Factors(const T& NUMBER);

template <class T>
T NumberOfFactors(const T& NUMBER);

template <class T>
T SumOfFactors(const T& NUMBER);

// Templated function implementations
#include "alexlib.tcc"  // Factors, NumberOfFactors, SumOfFactors

#endif  // ALEXLIB_H_
