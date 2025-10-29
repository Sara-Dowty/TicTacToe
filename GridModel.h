//
// Created by dowty on 6/10/2025.
//

#ifndef GRIDMODEL_H
#define GRIDMODEL_H
#include "Grid.h"
#include "Mark.h"
#include<map>
#include<vector>
#include<string> //future naming?


class GridModel {
public:
    GridModel();
    const Grid& getGrid() const;

    //---Using names
    bool hasMark(const string& squareName, Mark mark);
    [[nodiscard]] bool isSquareEmpty(const string& squareName) const;
    [[nodiscard]] Mark getMarkInGrid(const string& squareName) const;
    //---Game Information
    bool reset();
    bool isGridWin(Mark& mark, string& winningRow); //check full grid for wi
    bool isFull() const;
    //ACCESSORS - FOR UI/VIEW LATER
    [[nodiscard]] vector<string> getALLSquareNames() const;
    //[[nodiscard]] vector<string> getAllRowNames() const; //previous version
    [[nodiscard]] const vector<Square*>& getSquaresInRow(const string& rowName) const;
    const Grid& getGridModel();
private:
    Grid grid_data;
    //---Name
    map<string, Square*> square_map;
    map<string, vector<Square*>> row_map;
    //internal methods
    void initializeMaps(); //called by constructor & reset()
    static string rowToSquareName(int row, int row2) ;
};



#endif //GRIDMODEL_H
