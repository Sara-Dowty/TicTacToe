//Sara Dowty
//Object Orientation

#include <iostream>
//#include "testRow.h"
//#include "testPlayer.h"
#include "TicTacToe.h"

using namespace std;

// This function will run all the tests defined in the TestRow class
/*void run_all_row_tests() {
    TestRow rowTestSuite;
    rowTestSuite.runAllTests();
}
// This function will run all the tests defined in the TestPlayer class
void run_all_player_tests() {
    TestPlayer playerTestSuite;
    playerTestSuite.runAllTests();
}
*/

int main(int argc, char *argv[]) {
    cout << "Application: Starting TicTacToe..." << std::endl;

    // --- Execute Tests for Square Class ---
    //TestSquare squareTestRunner; // Create an instance of our test class
    //squareTestRunner.runAllTests(); // Call the method that runs all tests
    //TEST for Row Class
    //run_all_row_tests();
    //TEST for Grid Class
    //TestGrid gridTestRunner;
    //gridTestRunner.runAllTests();
    //testing player
    //run_all_player_tests();
    /*Grid game1;
    game1.addMark("topLeftSquare", Mark::X);
    game1.addMark("topRightSquare", Mark::O);
    game1.addMark("bottomLeftSquare", Mark::X);
    game1.addMark("center", Mark::O);
    GridView game1View(game1);
    game1View.displayWelcomeMessage();
    game1View.displayGrid();
    game1View.playerTurnprompt(Mark::X);
    */
    //PLAY TICTACTOE
    TicTacToe game1;
    game1.startGame();

    cout << "Application: Shutting down." << std::endl;
    // ... any further logic of your main application ...


    return 0;
}