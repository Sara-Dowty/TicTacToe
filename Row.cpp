//
// Created by dowty on 6/2/2025.
//

#include "Row.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Row::Row() {
    for (int i = 0; i < 3; i++) {
        squares_in_row.emplace_back();
    }
}
//return reference to square
Square& Row::getSquare(int index) {
    return squares_in_row.at(index);
}
//Reading Only - square reference
const Square& Row::getSquare(int index) const {
    return squares_in_row.at(index);
}
//TEST - Set mark in square.
bool Row::setMarkInSquare(int index, Mark markToTest) {
    try {
        squares_in_row.at(index).set_mark(markToTest);
        return true;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
        return false;
    }
}
//TEST - Row is a win
bool Row::isWin(Mark &markToTest) const {
    if (squares_in_row.size() != 3) {
        return false;
    }
    if (squares_in_row.at(0).is_empty() || squares_in_row.at(1).is_empty() || squares_in_row.at(2).is_empty()) {
        return false;
    }
    //get square marks
    Mark mark1 = squares_in_row.at(0).get_mark();
    Mark mark2 = squares_in_row.at(1).get_mark();
    Mark mark3 = squares_in_row.at(2).get_mark();
    //checks if marks are the same
    if (mark1 == mark2 && mark2 == mark3) {
        markToTest = mark1;
        return true;
    }
    return false;
}


