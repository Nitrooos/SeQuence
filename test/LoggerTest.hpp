#include "../src/Logger.hpp"
#include "../src/Event.hpp"

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
            l.saveResult(ResultEvent());

            ifstream L("log"), R("results");
            string temp;

            getline(L, temp);
            CPPUNIT_ASSERT(temp == "Instance data/instances/9.200-40 loaded");
            getline(L, temp);
            CPPUNIT_ASSERT(temp == "Instance data/instances/53.500+200 loaded");
            getline(R, temp);
            CPPUNIT_ASSERT(temp == "JAKIŚ REZULTAT");
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(LoggerTest);
