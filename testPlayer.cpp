//
// Created by dowty on 6/10/2025.
//

#include "testPlayer.h"
#include "Player.h" // Include the full definition of the Player class
#include "Mark.h"   // For Mark::X and Mark::O
#include <iostream>

TestPlayer::TestPlayer() : testsPassedCount(0), testsFailedCount(0) {}

void TestPlayer::reportTestResult(const std::string& testName, bool passed, const std::string& message) {
    if (passed) {
        testsPassedCount++;
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        testsFailedCount++;
        std::cout << "[FAIL] " << testName;
        if (!message.empty()) {
            std::cout << " - Details: " << message;
        }
        std::cout << std::endl;
    }
}

// --- Test Case Implementations ---

bool TestPlayer::testAssignAndGetMark_AssignsX() {
    std::string testName = "Player.AssignAndGet.AssignsX";
    bool passed = false;
    std::string failureMessage = "";

    try {
        Player p;
        p.assignMark(Mark::X);
        Mark result = p.getMark();

        if (result == Mark::X) {
            passed = true;
        } else {
            failureMessage = "getMark() did not return Mark::X after assignMark(Mark::X) was called.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "An unexpected exception occurred: " + std::string(e.what());
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestPlayer::testAssignAndGetMark_AssignsO() {
    std::string testName = "Player.AssignAndGet.AssignsO";
    bool passed = false;
    std::string failureMessage = "";

    try {
        Player p;
        p.assignMark(Mark::O);
        Mark result = p.getMark();

        if (result == Mark::O) {
            passed = true;
        } else {
            failureMessage = "getMark() did not return Mark::O after assignMark(Mark::O) was called.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "An unexpected exception occurred: " + std::string(e.what());
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestPlayer::testReassignMark_CanChangeMark() {
    std::string testName = "Player.AssignAndGet.ReassignsMark";
    bool passed = false;
    std::string failureMessage = "";

    try {
        Player p;
        p.assignMark(Mark::X); // First assignment
        p.assignMark(Mark::O); // Second assignment should overwrite
        Mark result = p.getMark();

        if (result == Mark::O) {
            passed = true;
        } else {
            failureMessage = "getMark() did not return Mark::O after re-assigning the mark.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "An unexpected exception occurred: " + std::string(e.what());
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}


// --- Test Runner Method ---
void TestPlayer::runAllTests() {
    testsPassedCount = 0;
    testsFailedCount = 0;

    std::cout << "\n--- Running Player Class Tests ---" << std::endl;

    testAssignAndGetMark_AssignsX();
    testAssignAndGetMark_AssignsO();
    testReassignMark_CanChangeMark();

    std::cout << "\n--- Player Test Summary ---" << std::endl;
    unsigned int totalTests = testsPassedCount + testsFailedCount;
    std::cout << "Total tests run: " << totalTests << std::endl;
    std::cout << "Tests Passed: " << testsPassedCount << std::endl;
    std::cout << "Tests Failed: " << testsFailedCount << std::endl;
    std::cout << "-------------------------\n" << std::endl;
}