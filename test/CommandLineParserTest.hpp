#include "../src/CommandLineParser.hpp"
#include "../src/Options.hpp"

class ParserTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(ParserTest);
    CPPUNIT_TEST(argumentsTest);
    CPPUNIT_TEST_SUITE_END();

    public:
        void argumentsTest() {
            char *argv[] = { "debug/SeQuence", "-s", "11", "-m", "8", "-t", "100" };
            Parser::setProgramOptions(7, argv);

            CPPUNIT_ASSERT(Options::getInstance().getSolutionsNumber() == 11);
            CPPUNIT_ASSERT(Options::getInstance().getMinCommonPart() == 8);
            CPPUNIT_ASSERT(Options::getInstance().getTimeout() == 100);
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ParserTest);
