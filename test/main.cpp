#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "../src/mystring.h"

class mystringTest : public CppUnit::TestCase {
    public:
        void runTest() {
            mystring s;
            s.setbuffer("Siema");
            CPPUNIT_ASSERT_MESSAGE("String Length Non-Zero", s.size() == 5);
        }
};

int main () {
    mystringTest test;
    CppUnit::TextTestRunner runner;
    runner.addTest(&test);

    runner.run();
    return 0;
}
