//
// Created by dowty on 6/10/2025.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridView.h"
#include "GridModel.h"
#include "Player.h"
#include "Mark.h"
#include <string>

class TicTacToe {
public:
    //Constructor initializing game
    TicTacToe();
    //Initializing  the game
    void startGame();
private:
    //Variable
    GridModel gridModel;  //Holding the game state
    GridView gridView;  //Displaying grid & messages
    Player player1; //Player1, X
    Player player2; //Player2, O
    Mark currentPlayerMark; //Tracking turn 'X' or 'O'
    //Helper functions
    void initializeGame(); //Setting up player marks, starting grid
    void gameLoop(); //Contains the main game for player turn
    void handlePlayerTurn(); //Managing player turn
    void switchPlayerTurn(); //Switching from X to O and O to X
    bool isGameOver(); //Checking game win, cats game, full
    //Mapping user input square numbers with name
    [[nodiscard]] std::string inputToSquareName(const std::string input) const;
};



#endif //TICTACTOE_H
