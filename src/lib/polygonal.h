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

#ifndef POLYGONALLIB_H_
#define POLYGONALLIB_H_

#include <inttypes.h>  // uint_fast64_t


uint_fast32_t TriangleNumber(const uint_fast32_t& NTH);

bool IsPolygonal(
    const uint_fast64_t& NUMBER,
    const uint_fast32_t& MULTIPLIER,
    const double& DIVISOR
);

bool IsTriangular(const uint_fast64_t& NUMBER);

bool IsPentagonal(const uint_fast64_t& NUMBER);

bool IsHexagonal(const uint_fast64_t& NUMBER);


#endif  // POLYGONALLIB_H_
