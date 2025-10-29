//
// Created by dowty on 6/2/2025.
//

#ifndef ROW_H
#define ROW_H
#include "Square.h"
#include <vector>
#include <string> //labels?

class Row {
public:
    //Constructor
    Row();

    //modifying square
    Square& getSquare(int index);
    //reference point only
    const Square& getSquare(int index) const;
    //TEST-set mark on square, return true if successful
    bool setMarkInSquare(int index, Mark markToTest);
    //TEST-Mark for winning symbols. Returns true if a win.
    bool isWin(Mark& markToTest) const;

private:
    std::vector<Square> squares_in_row;
    };



#endif //ROW_H
