//
// Created by dowty on 6/10/2025.
//

// File: TestPlayer.h
#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H

#include <string>

// We don't need to include Player.h here, as we can forward-declare it.
// The .cpp file will need the full include.
class Player;

class TestPlayer {
public:
    TestPlayer();

    // The main function to call to run all tests for the Player class.
    void runAllTests();

private:
    // --- Test Case Methods ---
    bool testAssignAndGetMark_AssignsX();
    bool testAssignAndGetMark_AssignsO();
    bool testReassignMark_CanChangeMark();

    // --- Helper Method ---
    void reportTestResult(const std::string& testName, bool passed, const std::string& message = "");
    unsigned int testsPassedCount;
    unsigned int testsFailedCount;
};

#endif //TEST_PLAYER_H