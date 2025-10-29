//
// Created by dowty on 6/2/2025.
//
// File: TestRow.h
#ifndef TEST_ROW_H
#define TEST_ROW_H

#include "Row.h"    // The class we are testing
#include "Mark.h"   // For using Mark::X, Mark::O
#include <string>   // For test names and messages

class TestRow {
public:
    TestRow(); // Constructor

    // This is the main function to call to run all tests for the Row class
    void runAllTests();

private:
    // --- Individual Test Case Methods ---
    // Each method tests a specific piece of functionality.
    // They typically return true if the test passes, false otherwise,
    // and use reportTestResult to log the outcome.

    // Constructor Tests
    bool testConstructor_InitializesAllSquaresAsEmpty();

    // getSquare Tests
    bool testGetSquare_ValidIndex_ReturnsWritableSquare();
    bool testGetSquare_ConstVersion_ValidIndex_ReturnsReadableSquare();
    bool testGetSquare_InvalidIndex_ThrowsException();
    bool testGetSquare_ConstVersion_InvalidIndex_ThrowsException();

    // setMarkInSquare Tests
    bool testSetMarkInSquare_ValidEmptySquare();
    bool testSetMarkInSquare_OnAlreadyMarkedSquare(); // Assuming Square::set_mark throws and Row::setMarkInSquare catches & returns false
    bool testSetMarkInSquare_InvalidIndex_ReturnsFalse();

    // checkForWin Tests
    bool testCheckForWin_EmptyRow_NoWin();
    bool testCheckForWin_PartialRow_NoWin();
    bool testCheckForWin_FullRow_NoWin_MixedMarks();
    bool testCheckForWin_FullRow_WinningRowX();
    bool testCheckForWin_FullRow_WinningRowO();

    // --- Helper Methods ---
    void reportTestResult(const std::string& testName, bool passed, const std::string& message = "");
    unsigned int testsPassedCount;
    unsigned int testsFailedCount;
};

#endif //TEST_ROW_H