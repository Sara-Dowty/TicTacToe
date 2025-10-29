//
// Created by dowty on 6/10/2025.
//

#ifndef GRIDVIEW_H
#define GRIDVIEW_H

#include "GridModel.h"
#include "Mark.h"
#include <string>

using namespace std;

class GridView {
public:
    //Constructor taking in a constant reference to the grid model. Reading only.
    GridView(const GridModel& grid_model);

    //Displays the current state of TicTacToe
    void displayGrid() const;

    //Display methods for the game controller to call
    void displayWelcomeMessage() const;
    void displayWinner(Mark winnerMark, const string& winningRow) const;
    void displayCatsGame() const;
    void displayInvalidMoveMessage(const string& winningRow) const;
    void playerTurnprompt(Mark playerMark) const;

    void playAgain() const;

    void displayGameOver() const;

private:
    const GridModel& grid_model; //referencing the model
    //function to switch Mark enum to char
    char markToChar(Mark mark) const;

};



#endif //GRIDVIEW_H
