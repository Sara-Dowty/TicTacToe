//
// Created by dowty on 6/2/2025.
//

// File: test_Square.h
#ifndef TEST_SQUARE_H
#define TEST_SQUARE_H

#include "Square.h" // Your Square class
#include "Mark.h"   // The Mark enum
#include <string>   // For test names and messages
#include <vector>   // Potentially for collecting messages

class TestSquare {
public:
    TestSquare(); // Constructor to initialize counters

    // --- Individual Test Case Methods ---
    // Each method will test a specific functionality.
    // They return true if the test passes, false otherwise.
    bool checkConstructorInitializesEmpty();
    bool checkGetMarkOnEmptyThrowsException();

    bool checkSetMarkOnEmptyWorks();
    bool checkSetMarkOnMarkedSquareThrows();
    // ...

    // --- Test Runner Method ---
    // This method will call all individual test case methods and summarize results.
    void runAllTests();

private:
    // Helper method to report the result of a single test
    void reportTestResult(const std::string& testName, bool passed, const std::string& message = "");

    // Counters for test results
    unsigned int testsPassedCount;
    unsigned int testsFailedCount;

    // --- Hypothetical Test Methods (if Square logic changes) ---
    // bool checkSetMarkMakesSquareNonEmpty();
    // bool checkGetMarkReturnsCorrectMark();
};

#endif //TEST_SQUARE_H