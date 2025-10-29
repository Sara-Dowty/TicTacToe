//
// Created by dowty on 6/3/2025.
//

#ifndef GRID_H
#define GRID_H
#include "Row.h"
#include "Mark.h"
#include<vector>

using namespace std;

class Grid {
public:
    Grid();
    bool hasMark(int r1, int r2, Mark mark);
    [[nodiscard]] bool isSquareEmpty(int r1, int r2) const;
    //[[nodiscard]] bool isSquareMarked(const string& squareName) const;
    [[nodiscard]] Mark getMarkInGrid(int r1, int r2) const;
    void resetGrid();
    [[nodiscard]] bool isGridFull() const; // check is entire grid is full

    //Accessors for GridModel to use
    Square* getSquarePtr(int row1, int row2);
    [[nodiscard]] const Square *getSquarePtr(int row1, int row2) const;

private:
    vector<Row> grid; //row storage. Storing 3 row objects
    static bool isValidSquarePosition(int row, int row2);
};



#endif //GRID_H
