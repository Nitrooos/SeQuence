#include "../src/app/Options.hpp"

class OptionsTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(OptionsTest);
    CPPUNIT_TEST(argumentsTest);
    CPPUNIT_TEST_SUITE_END();

    public:
        void argumentsTest() {
            char *argv[] = { "debug/SeQuence", "-m", "8", "-l", "mylog.txt", "-f", "data/negative/9.200-40" };
            Options::getInstance().load(7, argv);

            CPPUNIT_ASSERT(Options::getInstance().getMinCommonPart() == 8);
            CPPUNIT_ASSERT(Options::getInstance().getLogFilename() == "mylog.txt");
            CPPUNIT_ASSERT(Options::getInstance().getInstanceFilename() == "data/negative/9.200-40");
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(OptionsTest);
