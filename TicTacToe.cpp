//
// Created by dowty on 6/10/2025.
//

#include "TicTacToe.h"
#include <iostream>
#include <string>

using namespace std;
//Constructor
TicTacToe::TicTacToe() : gridModel(), gridView (gridModel){
    //Default empty
}
//Starting the TicTacToe Game
void TicTacToe::startGame() {
    gridView.displayWelcomeMessage();
    initializeGame();
    gameLoop();
    gridView.displayGameOver();
    }
//TicTacToe main game loop until gameover
void TicTacToe::initializeGame() {
    gridModel.reset();
    player1.assignMark(Mark::X);
    player2.assignMark(Mark::O);
    currentPlayerMark = Mark::X; //Player1 X always starts
}
//GameLoop
void TicTacToe::gameLoop() {
    while (true) {
        gridView.displayGrid();
        handlePlayerTurn();

        if (isGameOver()) {
            break;
        }
        switchPlayerTurn();
    }
}

//Switching current player mark
void TicTacToe::switchPlayerTurn() {
    currentPlayerMark = (currentPlayerMark == Mark::X) ? Mark::O : Mark::X;
}
//Managing input and placing a mark
void TicTacToe::handlePlayerTurn() {
    while (true) {
        gridView.playerTurnprompt(currentPlayerMark);
        string input;
        cin >> input;
        //HERE
        string squareName = inputToSquareName(input);
        if (!squareName.empty() && gridModel.hasMark(squareName, currentPlayerMark)) {
            break; //Valid move
        } else {
            gridView.displayInvalidMoveMessage(input); //Invalid move input. PromptAgain.
        }
    }
}
//bool is gameover: win, catsgame, full
bool TicTacToe::isGameOver() {
    Mark winner;
    string winningRow;

    if (gridModel.isGridWin(winner, winningRow)) {
        gridView.displayGrid();
        gridView.displayWinner(winner, winningRow);
        return true; //game is over = winner!
    }
    if (gridModel.isFull()) {
        gridView.displayGrid();
        gridView.displayCatsGame();
        return true; //game is full & over
    }
    return false; //Game is NOT over
}
//Converting the rows
std::string TicTacToe::inputToSquareName(const std::string input) const {
    if (input == "1") return "topLeftSquare";
    if (input == "2") return "topMiddleSquare";
    if (input == "3") return "topRightSquare";
    if (input == "4") return "middleLeftSquare";
    if (input == "5") return "center";
    if (input == "6") return "middleRightSquare";
    if (input == "7") return "bottomLeftSquare";
    if (input == "8") return "bottomMiddleSquare";
    if (input == "9") return "bottomRightSquare";

    return ""; // Return empty string for invalid input
}
