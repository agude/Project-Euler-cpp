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
 * Su Doku (Japanese meaning number place) is the name given to a popular
 * puzzle concept. Its origin is unclear, but credit must be attributed to
 * Leonhard Euler who invent
 *
 * puzzle:   003020600900305001001806400008102900700000008006708200002609500800203009005010300
 * solution: 483921657967345821251876493548132976729564138136798245372689514814253769695417382
 *
 * A well constructed Su Doku puzzle has a unique solution and can be solved by
 * logic, although it may be necessary to employ "guess and test" methods in
 * order to eliminat
 *
 * The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'),
 * contains fifty different Su Doku puzzles ranging in difficulty, but all with
 * unique solutions (
 *
 * By solving all fifty puzzles find the sum of the 3-digit numbers found in
 * the top left corner of each solution grid; for example, 483 is the 3-digit
 * number found in the
 */

#include    <iostream>
//#include    <fstream>
#include    <stdlib.h>
#include    <string>

struct Coordinate {
    short col;
    short row;
};

/*
 * =====================================================================================
 *        Class:  Grid
 *  Description:  Stores a Sudoku board and solves it
 * =====================================================================================
 */
class Grid {
  private:
    // Gameboard
    short m_grid[9][9];
    bool  m_possible[9][9][9];
    Coordinate* returnRow( short i, short j);
    Coordinate* returnCol( short i, short j);
    Coordinate* returnSqr( short i, short j);
    void pullNeighbors( short i, short j);
    void pullConstraints( short i, short j);
    void cSqr( short i, short j);
    void cRow( short i, short j);
    void cCol( short i, short j);
    void checkCell( short i, short j);
    short strtoint(char str);
    bool solved;
    bool checkSolved();

  public:
    Grid(const std::string inPuzzle);
    void printGrid();
};

/*-----------------------------------------------------------------------------
 * Construtor
 *-----------------------------------------------------------------------------*/
Grid::Grid (const std::string inPuzzle) {
    solved = false;

    // Blank gameboard and possibilites
    for ( short i = 0 ; i < 9 ; i++ ) {
        for ( short j = 0 ; j < 9 ; j++ ) {
            const char puz = inPuzzle[i * 9 + j];
            const int val = strtoint(puz);
            m_grid[i][j] = val;

            for ( short k = 0 ; k < 9 ; k++ ) {
                if (val == 0 || k == val - 1) { // All values still possible
                    m_possible[i][j][k] = true;
                } else {
                    m_possible[i][j][k] = false;
                }
            }
        }
    }

    printGrid();

    for ( int z = 0; z < 100; z++) {
        for ( short i = 0 ; i < 9 ; i++ ) {
            for ( short j = 0 ; j < 9 ; j++ ) {
                checkCell(i, j);
                pullNeighbors(i, j);
                checkCell(i, j);
                pullConstraints(i, j);
                checkCell(i, j);
            }
        }
    }

    std::cout << std::endl;
    printGrid();
}

/*-----------------------------------------------------------------------------
 *  Return the coordinates of groupings of cells (rows, cols, squares)
 *-----------------------------------------------------------------------------*/
Coordinate* Grid::returnRow( const short i, const short j) {
    Coordinate* Row = new Coordinate[8];
    short l = 0;

    for ( short k = 0; k < 9; k++) {
        if ( k != j ) { // We don't want the cell we're looking at in the row
            Row[l].row = i;
            Row[l].col = k;
            l++;
        }
    }

    return Row;
}

Coordinate* Grid::returnCol( short i, short j) {
    Coordinate* Col = new Coordinate[8];
    short l = 0;

    for ( short k = 0; k < 9; k++) {
        if ( k != i ) { // We don't want the cell we're looking at in the col
            Col[l].row = k;
            Col[l].col = j;
            l++;
        }
    }

    return Col;
}

Coordinate* Grid::returnSqr( short i, short j) {
    Coordinate* Sqr = new Coordinate[8];
    short rowStart, rowEnd;
    short colStart, colEnd;

    switch ( i ) {
    case 0:
    case 1:
    case 2:
        rowStart = 0;
        rowEnd = 3;
        break;

    case 3:
    case 4:
    case 5:
        rowStart = 3;
        rowEnd = 6;
        break;

    case 6:
    case 7:
    case 8:
        rowStart = 6;
        rowEnd = 9;
        break;

    default:
        break;
    }

    switch ( j ) {
    case 0:
    case 1:
    case 2:
        colStart = 0;
        colEnd = 3;
        break;

    case 3:
    case 4:
    case 5:
        colStart = 3;
        colEnd = 6;
        break;

    case 6:
    case 7:
    case 8:
        colStart = 6;
        colEnd = 9;
        break;

    default:
        break;
    }

    short m = 0;

    for ( short k = rowStart; k < rowEnd; k++ ) {
        for ( short l = colStart; l < colEnd; l++ ) {
            if (i != k || j != l) {
                Sqr[m].row = k;
                Sqr[m].col = l;
                m++;
            }
        }
    }

    return Sqr;
}

/*-----------------------------------------------------------------------------
 *  Our two propegation methods.
 *-----------------------------------------------------------------------------*/
void Grid::pullNeighbors( const short i, const short j) {
    /*
      Given a cell, c at i,j, checks all other cells connected to c
      and removes values from c's possiblity array.
     */
    //std::cout << "Checking " << i << ' ' << j << ':' << std::endl;

    bool* pos[9];

    for ( short k = 0; k < 9; k++) {
        pos[k] = &m_possible[i][j][k];
        //std::cout << ' ' << k+1 << ':' << *pos[k];
    }

    //std::cout << std::endl;

    Coordinate* sqr;
    sqr = returnSqr(i, j);

    for ( short k = 0; k < 8; k++) {
        const short m = sqr[k].row;
        const short n = sqr[k].col;
        const short val = m_grid[m][n];

        if (val != 0) {
            //std::cout << "\tFound value " << val << " at " << m << ' ' << n << std::endl;
            *pos[val - 1] = false;
        }
    }

    Coordinate* row;
    row = returnRow(i, j);

    for ( short k = 0; k < 8; k++) {
        const short m = row[k].row;
        const short n = row[k].col;
        const short val = m_grid[m][n];

        if (val != 0) {
            //std::cout << "\tFound value " << val << " at " << m << ' ' << n << std::endl;
            *pos[val - 1] = false;
        }
    }

    Coordinate* col;
    col = returnCol(i, j);

    for ( short k = 0; k < 8; k++) {
        const short m = col[k].row;
        const short n = col[k].col;
        const short val = m_grid[m][n];

        if (val != 0) {
            //std::cout << "\tFound value " << val << " at " << m << ' ' << n << std::endl;
            *pos[val - 1] = false;
        }
    }

    for ( short k = 0; k < 9; k++) {
        pos[k] = &m_possible[i][j][k];
        //std::cout << ' ' << k+1 << ':' << *pos[k];
    }

    //std::cout << std::endl;
    //std::cout << std::endl;
}

void Grid::pullConstraints( const short i, const short j) {
    /*
     * If a cell is the only sell in its row/col/sqr
     * that can take a value, it must be that value
     */

    if ( m_grid[i][j] == 0 ) {
        cSqr(i, j);
        checkCell(i, j);
    }

    if ( m_grid[i][j] == 0 ) {
        cRow(i, j);
        checkCell(i, j);
    }

    if ( m_grid[i][j] == 0 ) {
        cCol(i, j);
        checkCell(i, j);
    }

}

void Grid::cSqr( const short i, const short j) {
    //std::cout << "Checking contraints on " << i << ' ' << j << ':' << std::endl;
    bool onlyHere[8];

    for ( short l = 0; l < 9; l++) {
        onlyHere[l] = m_possible[i][j][l];
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    Coordinate* sqr;
    sqr = returnSqr(i, j);

    for ( short k = 0; k < 8; k++) {
        const short  m = sqr[k].row;
        const short  n = sqr[k].col;

        for ( short l = 0; l < 9; l++) {
            if (m_possible[m][n][l]) {
                onlyHere[l] = false;
            }
        }
    }

    for ( short l = 0; l < 9; l++) {
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    short ntrue = 0;
    short val = 0;

    for ( short l = 0; l < 9; l++) {
        if (onlyHere[l]) {
            val = l + 1;
            ntrue++;
        }
    }

    if (ntrue == 1) {
        std::cout << "CONSTRAINED by Sqr!" << std::endl;
        m_grid[i][j] = val;
    }
}

void Grid::cCol( const short i, const short j) {
    //std::cout << "Checking contraints on " << i << ' ' << j << ':' << std::endl;
    bool onlyHere[8];

    for ( short l = 0; l < 9; l++) {
        onlyHere[l] = m_possible[i][j][l];
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    Coordinate* col;
    col = returnCol(i, j);

    for ( short k = 0; k < 8; k++) {
        const short m = col[k].row;
        const short n = col[k].col;

        for ( short l = 0; l < 9; l++) {
            if (m_possible[m][n][l]) {
                onlyHere[l] = false;
            }
        }
    }

    for ( short l = 0; l < 9; l++) {
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    short ntrue = 0;
    short val = 0;

    for ( short l = 0; l < 9; l++) {
        if (onlyHere[l]) {
            val = l + 1;
            ntrue++;
        }
    }

    if (ntrue == 1) {
        std::cout << "CONSTRAINED by Col!" << std::endl;
        m_grid[i][j] = val;
    }
}

void Grid::cRow( const short i, const short j) {
    //std::cout << "Checking contraints on " << i << ' ' << j << ':' << std::endl;
    bool onlyHere[8];

    for ( short l = 0; l < 9; l++) {
        onlyHere[l] = m_possible[i][j][l];
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    Coordinate* row;
    row = returnRow(i, j);

    for ( short k = 0; k < 8; k++) {
        const short m = row[k].row;
        const short n = row[k].col;

        for ( short l = 0; l < 9; l++) {
            if (m_possible[m][n][l]) {
                onlyHere[l] = false;
            }
        }
    }

    for ( short l = 0; l < 9; l++) {
        //std::cout << l+1 << ':' << onlyHere[l] << ' ';
    }

    //std::cout << std::endl;

    short ntrue = 0;
    short val = 0;

    for ( short l = 0; l < 9; l++) {
        if (onlyHere[l]) {
            val = l + 1;
            ntrue++;
        }
    }

    if (ntrue == 1) {
        std::cout << "CONSTRAINED BY ROW!" << std::endl;
        m_grid[i][j] = val;
    }
}

void Grid::checkCell( const short i, const short j) {
    /*
     * If a cell has only one possibilty left, assign it.
     */
    short ntrue = 0;
    short val = 0;

    for ( short k = 0; k < 9; k++) {
        if (m_possible[i][j][k]) {
            val = k + 1;
            ntrue++;
        }
    }

    if (ntrue == 1) {
        m_grid[i][j] = val;
    }
}

/*-----------------------------------------------------------------------------
 *  Check the solution for completeness
 *-----------------------------------------------------------------------------*/

bool Grid::checkSolved() {
    // Check all numbers filled
    for ( short i = 0; i > 9; i++) {
        for ( short j = 0; j > 9; j++) {
            if (m_grid[i][j] == 0) {
                return false;
            }
        }
    }

    // Check that sums of rows, columns are right
    short rowSum, colSum;

    for ( short i = 0; i > 9; i++) {
        rowSum = colSum = 0;

        for ( short j = 0; j > 9; j++) {
            rowSum += m_grid[i][j];
            colSum += m_grid[j][i];
        }

        if (rowSum != 45 || colSum != 45) {
            return false;
        }
    }

    // TODO: Check sqr sum too

    return true;
}

/*-----------------------------------------------------------------------------
 *  Method to print the grid nicely
 *-----------------------------------------------------------------------------*/
void Grid::printGrid() {
    for ( short i = 0; i < 9; i++ ) {
        if ( i != 0 && i % 3 == 0) {
            std::cout << "-------+-------+-------" << std::endl;
        }

        for ( short j = 0; j < 9; j++ ) {
            if ( j != 0 && j % 3 == 0) {
                std::cout << " |";
            }

            std::cout << ' ' << m_grid[i][j];
        }

        std::cout << std::endl;
    }
}


/*-----------------------------------------------------------------------------
 *  Method to convert str to int. Better ways exist, needs replacement.
 *-----------------------------------------------------------------------------*/
short Grid::strtoint(char str) {

    switch ( str ) {
    case '0':
        return 0;

    case '1':
        return 1;

    case '2':
        return 2;

    case '3':
        return 3;

    case '4':
        return 4;

    case '5':
        return 5;

    case '6':
        return 6;

    case '7':
        return 7;

    case '8':
        return 8;

    case '9':
        return 9;
    }

    return -1;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Runs our solver
 * =====================================================================================
 */
int main () {
    //std::string s1="003020600900305001001806400008102900700000008006708200002609500800203009005010300";
    const std::string s1 = "080903040006107000003000600600089004900000003700640002009000300000806200010705090";

    Grid g(s1);
    //g.printGrid();

    return EXIT_SUCCESS;
}
