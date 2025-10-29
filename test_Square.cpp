//
// Created by dowty on 6/2/2025.
//

// File: test_Square.cpp
#include "test_Square.h"
#include <iostream>     // For std::cout
#include <stdexcept>    // For std::runtime_error

// Constructor
TestSquare::TestSquare() : testsPassedCount(0), testsFailedCount(0) {}

// Helper to report test results
void TestSquare::reportTestResult(const std::string& testName, bool passed, const std::string& message) {
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

bool TestSquare::checkConstructorInitializesEmpty() {
    std::string testName = "Square.Constructor.InitializesEmpty";
    bool passed = false;
    std::string failureMessage = "";

    try {
        Square s;
        if (s.is_empty()) {
            passed = true;
        } else {
            failureMessage = "Square should be empty upon construction (is_empty() returned false).";
        }
    } catch (const std::exception& e) {
        failureMessage = "An unexpected exception occurred: " + std::string(e.what());
        passed = false;
    } catch (...) {
        failureMessage = "An unknown unexpected exception occurred.";
        passed = false;
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestSquare::checkGetMarkOnEmptyThrowsException() {
    std::string testName = "Square.GetMark.ThrowsOnEmpty";
    bool passed = false;
    std::string failureMessage = "";
    Square s; // A new square is empty

    try {
        s.get_mark(); // This line should throw std::runtime_error
        // If we reach here, the exception was NOT thrown, which is a failure for this test.
        failureMessage = "Expected std::runtime_error was not thrown when calling get_mark() on an empty square.";
        passed = false;
    } catch (const std::runtime_error& e) {
        // Exception was thrown, now check if it's the correct one (optional, but good)
        if (std::string(e.what()) == "Square is empty") {
            passed = true; // Correct exception and message
        } else {
            failureMessage = "std::runtime_error thrown, but with incorrect message: \"" + std::string(e.what()) + "\" instead of \"Square is empty\".";
            passed = false;
        }
    } catch (const std::exception& e) {
        failureMessage = "An unexpected different type of exception occurred: " + std::string(e.what());
        passed = false;
    } catch (...) {
        failureMessage = "An unknown unexpected non-std::runtime_error exception occurred.";
        passed = false;
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestSquare::checkSetMarkOnEmptyWorks() {
    std::string testName = "Square.SetMark.OnEmptySquareWorks";
    bool passed = false;
    std::string failureMessage = "";
    Square s; // New square, is_empty() == true

    try {
        s.set_mark(Mark::X); // Should successfully mark the square
        if (s.is_empty()) {
            failureMessage = "is_empty() returned true after set_mark on an empty square.";
            passed = false;
        } else {
            // Now try to get the mark
            if (s.get_mark() == Mark::X) {
                passed = true; // Mark is correct and is_empty() is false
            } else {
                failureMessage = "get_mark() did not return the correct Mark after set_mark.";
                passed = false;
            }
        }
    } catch (const std::exception& e) {
        failureMessage = "An unexpected exception occurred: " + std::string(e.what());
        passed = false;
    } catch (...) {
        failureMessage = "An unknown unexpected exception occurred.";
        passed = false;
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

bool TestSquare::checkSetMarkOnMarkedSquareThrows() {
    std::string testName = "Square.SetMark.OnMarkedSquareThrows";
    bool passed = false;
    std::string failureMessage = "";
    Square s;

    try {
        s.set_mark(Mark::X); // First mark, should succeed
        // Now, s is no longer empty. Try to mark it again.
        s.set_mark(Mark::O); // This should throw std::runtime_error
        // If we reach here, the exception was NOT thrown.
        failureMessage = "Expected std::runtime_error was not thrown when calling set_mark() on an already marked square.";
        passed = false;
    } catch (const std::runtime_error& e) {
        if (std::string(e.what()) == "Square is already marked.") {
            passed = true; // Correct exception and message
        } else {
            failureMessage = "std::runtime_error thrown, but with incorrect message: \"" + std::string(e.what()) + "\".";
            passed = false;
        }
    } catch (const std::exception& e) {
        failureMessage = "An unexpected different type of exception occurred: " + std::string(e.what());
        passed = false;
    } catch (...) {
        failureMessage = "An unknown unexpected non-std::runtime_error exception occurred.";
        passed = false;
    }

    reportTestResult(testName, passed, failureMessage);
    return passed;
}

// --- Test Runner Implementation ---

void TestSquare::runAllTests() {
    // Reset counters for a fresh run
    testsPassedCount = 0;
    testsFailedCount = 0;

    std::cout << "\n--- Running Square Class Tests ---" << std::endl;

    checkConstructorInitializesEmpty();
    checkGetMarkOnEmptyThrowsException();

    checkSetMarkOnEmptyWorks();
    checkSetMarkOnMarkedSquareThrows();


    // If you add more test methods, call them here.
    // e.g., if Square logic changes to allow setting marks:
    // checkSetMarkMakesSquareNonEmpty();
    // checkGetMarkReturnsCorrectMark();

    std::cout << "\n--- Test Summary ---" << std::endl;
    std::cout << "Total tests run: " << (testsPassedCount + testsFailedCount) << std::endl;
    std::cout << "Tests Passed: " << testsPassedCount << std::endl;
    std::cout << "Tests Failed: " << testsFailedCount << std::endl;
    std::cout << "--------------------\n" << std::endl;

    if (testsFailedCount > 0) {
        std::cout << "At least one test FAILED." << std::endl;
    } else if ((testsPassedCount + testsFailedCount) == 0) {
        std::cout << "No tests were run." << std::endl;
    }
     else {
        std::cout << "All tests PASSED!" << std::endl;
    }
}