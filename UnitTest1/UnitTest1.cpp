#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <fstream>
#include "../lab9.2.2.cpp"  // Include your main code file here

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestClassifyCharacters)
        {
            // Create a temporary test file
            const std::string filename = "test.txt";
            std::ofstream testFile(filename);
            testFile << "Hello, world! 123. This is a test: 456, 789." << std::endl;
            testFile.close();

            // Output strings to hold the results
            std::string digits, alphabets, punctuations;

            // Call classifyCharacters and check the output
            classifyCharacters(filename, digits, alphabets, punctuations);

            // Verify digits
            Assert::AreEqual(std::string("123456789"), digits);

            // Verify alphabets (in order, ignoring case and spaces)
            Assert::AreEqual(std::string("HelloworldThisisatest"), alphabets);

            // Verify punctuations
            Assert::AreEqual(std::string(",!.:,."), punctuations);

            // Clean up the test file
            remove(filename.c_str());
        }
    };
}
