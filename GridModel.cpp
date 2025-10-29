//
// Created by dowty on 6/10/2025.
//

#include "GridModel.h"
#include <stdexcept>
#include <bits/streambuf_iterator.h>
using namespace std;

GridModel::GridModel() {
    initializeMaps();
}
const Grid& GridModel::getGrid() const {
    return this->grid_data;
}
//Square Names & Row Num accessor List
string GridModel::rowToSquareName(int row, int row2) {
    if (row == 0) {
        if (row2 == 0) {return "topLeftSquare";};
        if (row2 == 1) {return "topMiddleSquare";};
        if (row2 == 2) {return "topRightSquare";};
    } else if (row == 1) {
        if (row2 == 0) {return "middleLeftSquare";};
        if (row2 == 1) {return "center";};
        if (row2 == 2) {return "middleRightSquare";};
    } else if (row == 2) {
        if (row2 == 0) {return "bottomLeftSquare";};
        if (row2 == 1) {return "bottomMiddleSquare";};
        if (row2 == 2) {return "bottomRightSquare";};
    }
    throw::out_of_range("Invalid location");
}
void GridModel::initializeMaps() {
    square_map.clear();
    row_map.clear();
    //Populate map from square names to square pointers
    for (int r1 =0; r1<3; r1++) {
        for (int r2 =0; r2<3; r2++) {
            string name = rowToSquareName(r1, r2);
            square_map[name] = grid_data.getSquarePtr(r1, r2);
        }
    } 
    //8 rows
    //horizontal
    row_map["topRow"] = {
        square_map.at("topLeftSquare"),
        square_map.at("topMiddleSquare"),
        square_map.at("topRightSquare") };
    row_map["middleRow"] = {
        square_map.at("middleLeftSquare"),
        square_map.at("center"),
        square_map.at("middleRightSquare") };
    row_map["bottomRow"] = {
        square_map.at("bottomLeftSquare"),
        square_map.at("bottomMiddleSquare"),
        square_map.at("bottomRightSquare") };
    // Vertical
    row_map["leftRow"] = {
        square_map.at("topLeftSquare"),
        square_map.at("middleLeftSquare"),
        square_map.at("bottomLeftSquare") };
    row_map["centerRow"] = {
        square_map.at("topMiddleSquare"),
        square_map.at("center"),
        square_map.at("bottomMiddleSquare") };
    row_map["rightRow"] = {
        square_map.at("topRightSquare"),
        square_map.at("middleRightSquare"),
        square_map.at("bottomRightSquare") };
    // Diagonal
    row_map["rightDiagonal"] = {
        square_map.at("topLeftSquare"),
        square_map.at("center"),
        square_map.at("bottomRightSquare") };
    row_map["leftDiagonal"] = {
        square_map.at("bottomLeftSquare"),
        square_map.at("center"),
        square_map.at("topRightSquare") };
}
//Using square position row numbers-keep?
bool GridModel:: hasMark(const string& squareName, Mark mark) {
    auto find = square_map.find(squareName);
    if (find == square_map.end() || find->second == nullptr) {
        return false;
    }
    Square* square_ptr = find->second;
    try {
        square_ptr->set_mark(mark);
        return true;
    } catch (const runtime_error&) {
        return false; //square already marked
    }
}
bool GridModel::isSquareEmpty(const string &squareName) const {
    auto find = square_map.find(squareName);
    if (find == square_map.end() || find->second == nullptr) {
        throw runtime_error("Square does not exist. Invalid square name: " + squareName);
    }
    return find->second->is_empty();
}
Mark GridModel::getMarkInGrid(const string &squareName) const {
    auto find1 = square_map.find(squareName);
    if ((find1 == square_map.end()) || find1->second == nullptr ){
        throw runtime_error("Invalid square name: " + squareName);
    }
    return find1->second->get_mark();
}
//game reset
bool GridModel::reset() {
    grid_data.resetGrid();
    initializeMaps(); //reinitializing pointers
    return true;
}
//Checks Grid for win
bool GridModel::isGridWin(Mark& mark, string& winningRow){
    for (const auto& pair : row_map) {
        const string& rowName = pair.first;
        const vector<Square*>& squares = pair.second;

        if (squares.at(0)->is_empty() ||
            squares.at(1)->is_empty() ||
            squares.at(2)->is_empty()) {
            continue;
            }
        //return & assign get_mark()
        Mark m1 = squares.at(0)->get_mark();
        Mark m2 = squares.at(1)->get_mark();
        Mark m3 = squares.at(2)->get_mark();
        if (m1 == m2 && m2 == m3) {
            mark = m1;
            winningRow = rowName;
            return true;
        }
    }
    winningRow = "";
    return false; //Not a winner
}
bool GridModel::isFull() const {
    return grid_data.isGridFull();
}

const vector<Square *> &GridModel::getSquaresInRow(const string &rowName) const {
    auto find = row_map.find(rowName);
    if (find != row_map.end()) {
        return find->second;
    }
    throw runtime_error("Invalid row name: " + rowName);
}
vector<string> GridModel::getALLSquareNames() const {
    vector<string> names;
    names.reserve(square_map.size()); // Reserve memory
    for(const auto& pair : square_map) {
        names.push_back(pair.first);
    }

    return names;
}
const Grid &GridModel::getGridModel() {
    return grid_data;
}
