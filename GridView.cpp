//
// Created by dowty on 6/10/2025.
//

#include "GridView.h"
#include <iostream>

GridView::GridView(const GridModel& grid_model) : grid_model(grid_model){
    //Referencing the grid model here
 }
//Switching Mark enum to a char for display purposes
char GridView::markToChar(Mark mark) const {
    switch (mark) {
        case Mark::X:
            return 'X';
        case Mark::O:
            return 'O';
        default:
            return ' ';
    }
}
//Core of the program. Displaying the grid.
void GridView::displayGrid() const {
    cout<<"\n";
    char position_char = '1'; //Display numbers in empty squares
    const Grid& grid = grid_model.getGrid();
    for (int r1 = 0; r1 < 3; r1++) {
        for (int r2 = 0; r2 < 3; r2++) {
            char display_char;
            if (grid.isSquareEmpty(r1, r2)) {
                //if square is empty - display number. Used for selection later
                display_char = position_char;
            } else {
                //If marked, get the mark and convert it to an 'X' or 'O'
                display_char = markToChar(grid.getMarkInGrid(r1, r2));
            }
            cout<< " "<<display_char<< " "; //review this output

            if(r2<2) {
                cout << "|"; //Developing a vertical line
            }
            position_char++;
        }
        cout<<"\n";
        if (r1 <2) {
            cout<< "---+---+---\n"; //Developing a horizontal line
        }
    }
    cout<<"\n";
}
//============Display Methods for Messages ==================

void GridView::displayWelcomeMessage() const {
    cout<<"================================\n";
    cout << "      Welcome to TicTacToe \n";
    cout<<"================================\n";
}

void GridView::displayWinner(Mark winnerMark, const string &winningRow) const {
    cout<<"********************************\n";
    cout<< "  Congratulations Player " << markToChar(winnerMark) << " wins!\n";
    cout<< "     On row: " << winningRow << endl;
    cout<<"********************************\n";
}

void GridView::displayCatsGame() const {
    cout<<"********************************\n";
    cout<<"       It's a cat's game!\n";
    cout<<"********************************\n";
}
void GridView::displayGameOver() const {
    cout<< "Game Over\n";
    cout<<"Thanks for playing"<<endl;
}
void GridView::displayInvalidMoveMessage(const string &row) const {
    cout<<" -----> Invalid Move/Input: " <<row;
    cout<<"\n Please try again.";
}
void GridView::playerTurnprompt(Mark playerMark) const {
    cout<<"Player (" <<markToChar(playerMark)<< ") enter your move (1 - 9): " <<endl;
    }
void GridView::playAgain() const {
    cout<<"\nPlay again? Enter (yes/no): ";
}

