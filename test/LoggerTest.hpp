#include "../src/helper/Logger.hpp"
#include "../src/helper/Event.hpp"

#include <fstream>

using namespace std;

class LoggerTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(LoggerTest);
    CPPUNIT_TEST(log);
    CPPUNIT_TEST_SUITE_END();

    public:
        void log() {
            Logger l;
            l.log(InstanceLoadedEvent("data/instances/9.200-40"));
            l.log(InstanceLoadedEvent("data/instances/53.500+200"));

            ifstream L("output/log");
            string temp;

            getline(L, temp);
            CPPUNIT_ASSERT(temp == "Instance data/instances/9.200-40 loaded");
            getline(L, temp);
            CPPUNIT_ASSERT(temp == "Instance data/instances/53.500+200 loaded");
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(LoggerTest);
