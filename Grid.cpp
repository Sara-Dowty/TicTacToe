//
// Created by dowty on 6/3/2025.
//

#include "Grid.h"
#include <stdexcept>
#include <vector>
#include "Square.h"
#include "Row.h"

using namespace std;

Grid::Grid() {
    //Initializing grid with 3 rows
    for (int row = 0; row < 3; row++) {
        grid.emplace_back();
    }
}

//validate positions first
bool Grid::isValidSquarePosition(int row, int row2) {
    return (row >=0 && row <3 && row2 >=0 && row2 <3);
}
//Accessing
Square *Grid::getSquarePtr(int row1, int row2) {
    if (!isValidSquarePosition(row1, row2)) {
        return nullptr;
    } return &grid.at(row1).getSquare(row2);

}
const Square *Grid::getSquarePtr(int row1, int row2) const {
    if (!isValidSquarePosition(row1, row2)) {
        return nullptr;
    } return &grid.at(row1).getSquare(row2);

}
//verifies ability to add mark in spot
bool Grid::hasMark(int r1, int r2, Mark mark) {
    Square* squarePtr = getSquarePtr(r1, r2);
    if (!squarePtr) {
        return false;
    }
    try {
        squarePtr ->set_mark(mark);
        return true;
    } catch (const runtime_error& e) {
        return false;
    }
}
//Verify unmarked square in grid
bool Grid::isSquareEmpty(int r1, int r2) const {
    const Square* square_ptr = getSquarePtr(r1, r2);
    if (!square_ptr) {
        throw out_of_range("Invalid square location");
    }
    return square_ptr->is_empty();
}
Mark Grid::getMarkInGrid(int r1, int r2) const {
    const Square* square_ptr = getSquarePtr(r1, r2);
    if (!square_ptr) {
        throw out_of_range("Invalid square location");
    }
    return square_ptr->get_mark();
}
//reset the grid to empty default
void Grid::resetGrid() {
    grid.clear();
    for (int row = 0; row < 3; row++) {
        grid.emplace_back();
    }
}
bool Grid::isGridFull() const {
    for (int row1 = 0; row1 < 3; row1++) {
        for (int row2 = 0; row2 < 3; row2++) {
            if (getSquarePtr(row1, row2)->is_empty()) {
                return false;
            }
        }
    }
    return true; //All squares checked, grid is full
}
