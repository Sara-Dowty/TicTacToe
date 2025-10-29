//
// Created by dowty on 6/2/2025.
//

// File: TestRow.cpp
#include "TestRow.h"
#include <iostream>     // For std::cout
#include <stdexcept>    // For std::out_of_range, std::runtime_error

// Constructor
TestRow::TestRow() : testsPassedCount(0), testsFailedCount(0) {}

// Helper to report test results
void TestRow::reportTestResult(const std::string& testName, bool passed, const std::string& message) {
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

// Constructor Tests
bool TestRow::testConstructor_InitializesAllSquaresAsEmpty() {
    std::string testName = "Row.Constructor.AllSquaresEmpty";
    bool passed = true;
    std::string failureMessage = "";
    try {
        Row r;
        for (int i = 0; i < 3; ++i) {
            if (!r.getSquare(i).is_empty()) {
                passed = false;
                failureMessage = "Square at index " + std::to_string(i) + " was not empty.";
                break;
            }
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

// getSquare Tests
bool TestRow::testGetSquare_ValidIndex_ReturnsWritableSquare() {
    std::string testName = "Row.GetSquare.ValidIndexWritable";
    bool passed = false;
    std::string failureMessage = "";
    try {
        Row r;
        Square& sq = r.getSquare(0); // Get a reference
        sq.set_mark(Mark::X);        // Modify it (assuming Square::set_mark allows this on empty)
        if (!r.getSquare(0).is_empty() && r.getSquare(0).get_mark() == Mark::X) {
            passed = true;
        } else {
            failureMessage = "Modification via getSquare(0) was not reflected.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestRow::testGetSquare_ConstVersion_ValidIndex_ReturnsReadableSquare() {
    std::string testName = "Row.GetSquare_Const.ValidIndexReadable";
    bool passed = false;
    std::string failureMessage = "";
    try {
        Row r_mut;
        r_mut.setMarkInSquare(1, Mark::O); // Setup a mark

        const Row r = r_mut; // Create a const Row (can be a copy or const ref)
        const Square& sq = r.getSquare(1); // Get const reference
        if (!sq.is_empty() && sq.get_mark() == Mark::O) {
            passed = true;
        } else {
            failureMessage = "Could not read correct state via const getSquare(1).";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestRow::testGetSquare_InvalidIndex_ThrowsException() {
    std::string testName = "Row.GetSquare.InvalidIndexThrows";
    bool passed = false;
    std::string failureMessage = "";
    Row r;
    try {
        r.getSquare(3); // Should throw
        failureMessage = "Expected std::out_of_range was not thrown for index 3.";
    } catch (const std::out_of_range&) {
        passed = true; // Correct exception
    } catch (const std::exception& e) {
        failureMessage = "Incorrect exception type: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestRow::testGetSquare_ConstVersion_InvalidIndex_ThrowsException() {
    std::string testName = "Row.GetSquare_Const.InvalidIndexThrows";
    bool passed = false;
    std::string failureMessage = "";
    const Row r;
    try {
        r.getSquare(-1); // Should throw
        failureMessage = "Expected std::out_of_range was not thrown for index -1 (const).";
    } catch (const std::out_of_range&) {
        passed = true; // Correct exception
    } catch (const std::exception& e) {
        failureMessage = "Incorrect exception type (const): " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}


// setMarkInSquare Tests
bool TestRow::testSetMarkInSquare_ValidEmptySquare() {
    std::string testName = "Row.SetMarkInSquare.ValidEmpty";
    bool passed = false;
    std::string failureMessage = "";
    try {
        Row r;
        bool success = r.setMarkInSquare(1, Mark::X);
        if (success && !r.getSquare(1).is_empty() && r.getSquare(1).get_mark() == Mark::X) {
            passed = true;
        } else if (!success) {
            failureMessage = "setMarkInSquare returned false for a valid operation.";
        } else {
            failureMessage = "Square state incorrect after setMarkInSquare.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestRow::testSetMarkInSquare_OnAlreadyMarkedSquare() {
    std::string testName = "Row.SetMarkInSquare.AlreadyMarked";
    bool passed = false;
    std::string failureMessage = "";
    try {
        Row r;
        r.setMarkInSquare(0, Mark::X); // First mark
        bool success = r.setMarkInSquare(0, Mark::O); // Attempt to overwrite
        // Expecting 'success' to be false because Square::set_mark should throw,
        // and Row::setMarkInSquare should catch and return false.
        if (!success && r.getSquare(0).get_mark() == Mark::X) { // Check it returned false and mark didn't change
            passed = true;
        } else if (success) {
            failureMessage = "setMarkInSquare returned true when marking an already marked square.";
        } else {
            failureMessage = "Mark changed or other unexpected state after attempting to mark an already marked square.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestRow::testSetMarkInSquare_InvalidIndex_ReturnsFalse() {
    std::string testName = "Row.SetMarkInSquare.InvalidIndexReturnsFalse";
    bool passed = false;
    std::string failureMessage = "";
    try {
        Row r;
        if (!r.setMarkInSquare(3, Mark::X) && !r.setMarkInSquare(-1, Mark::O)) {
            passed = true;
        } else {
            failureMessage = "setMarkInSquare did not return false for an invalid index.";
        }
    } catch (const std::exception& e) {
        passed = false;
        failureMessage = "Exception during test: " + std::string(e.what());
    }
    reportTestResult(testName, passed, failureMessage);
    return passed;
}

// checkForWin Tests
bool TestRow::testCheckForWin_EmptyRow_NoWin() {
    std::string testName = "Row.CheckForWin.EmptyRow";
    bool passed = false;
    Row r;
    Mark winner;
    if (!r.isWin(winner)) {
        passed = true;
    }
    reportTestResult(testName, passed, passed ? "" : "Empty row reported a win.");
    return passed;
}

bool TestRow::testCheckForWin_PartialRow_NoWin() {
    std::string testName = "Row.CheckForWin.PartialRowNoWin";
    bool passed = false;
    Row r;
    Mark winner;
    r.setMarkInSquare(0, Mark::X);
    r.setMarkInSquare(2, Mark::O);
    if (!r.isWin(winner)) {
        passed = true;
    }
    reportTestResult(testName, passed, passed ? "" : "Partial row reported a win.");
    return passed;
}

bool TestRow::testCheckForWin_FullRow_NoWin_MixedMarks() {
    std::string testName = "Row.CheckForWin.FullRowNoWinMixed";
    bool passed = false;
    Row r;
    Mark winner;
    r.setMarkInSquare(0, Mark::X);
    r.setMarkInSquare(1, Mark::O);
    r.setMarkInSquare(2, Mark::X);
    if (!r.isWin(winner)) {
        passed = true;
    }
    reportTestResult(testName, passed, passed ? "" : "Full row with mixed marks reported a win.");
    return passed;
}

bool TestRow::testCheckForWin_FullRow_WinningRowX() {
    std::string testName = "Row.CheckForWin.WinningRowX";
    bool passed = false;
    Row r;
    Mark winner = Mark::O; // Initialize with a different mark
    r.setMarkInSquare(0, Mark::X);
    r.setMarkInSquare(1, Mark::X);
    r.setMarkInSquare(2, Mark::X);
    if (r.isWin(winner) && winner == Mark::X) {
        passed = true;
    }
    reportTestResult(testName, passed, passed ? "" : "Winning row X not detected or wrong winner mark.");
    return passed;
}

bool TestRow::testCheckForWin_FullRow_WinningRowO() {
    std::string testName = "Row.CheckForWin.WinningRowO";
    bool passed = false;
    Row r;
    Mark winner = Mark::X; // Initialize with a different mark
    r.setMarkInSquare(0, Mark::O);
    r.setMarkInSquare(1, Mark::O);
    r.setMarkInSquare(2, Mark::O);
    if (r.isWin(winner) && winner == Mark::O) {
        passed = true;
    }
    reportTestResult(testName, passed, passed ? "" : "Winning row O not detected or wrong winner mark.");
    return passed;
}


// --- Test Runner Method ---
void TestRow::runAllTests() {
    testsPassedCount = 0;
    testsFailedCount = 0;

    std::cout << "\n--- Running Row Class Tests ---" << std::endl;

    // Constructor Tests
    testConstructor_InitializesAllSquaresAsEmpty();

    // getSquare Tests
    testGetSquare_ValidIndex_ReturnsWritableSquare();
    testGetSquare_ConstVersion_ValidIndex_ReturnsReadableSquare();
    testGetSquare_InvalidIndex_ThrowsException();
    testGetSquare_ConstVersion_InvalidIndex_ThrowsException();

    // setMarkInSquare Tests
    testSetMarkInSquare_ValidEmptySquare();
    testSetMarkInSquare_OnAlreadyMarkedSquare();
    testSetMarkInSquare_InvalidIndex_ReturnsFalse();

    // checkForWin Tests
    testCheckForWin_EmptyRow_NoWin();
    testCheckForWin_PartialRow_NoWin();
    testCheckForWin_FullRow_NoWin_MixedMarks();
    testCheckForWin_FullRow_WinningRowX();
    testCheckForWin_FullRow_WinningRowO();

    std::cout << "\n--- Row Test Summary ---" << std::endl;
    unsigned int totalTests = testsPassedCount + testsFailedCount;
    std::cout << "Total tests run: " << totalTests << std::endl;
    std::cout << "Tests Passed: " << testsPassedCount << std::endl;
    std::cout << "Tests Failed: " << testsFailedCount << std::endl;
    std::cout << "------------------------\n" << std::endl;

    if (testsFailedCount > 0) {
        std::cout << "ROW TESTS: AT LEAST ONE TEST FAILED." << std::endl;
    } else if (totalTests == 0) {
        std::cout << "ROW TESTS: NO TESTS WERE RUN." << std::endl;
    } else {
        std::cout << "ROW TESTS: ALL TESTS PASSED!" << std::endl;
    }
}