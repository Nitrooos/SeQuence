#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "ConverterTest.hpp"

int main () {
    ConverterTest test;
    CppUnit::TextTestRunner runner;
    runner.addTest(&test);

    runner.run();
    return 0;
}
