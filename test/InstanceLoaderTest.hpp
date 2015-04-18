#include "../src/InstanceLoader.hpp"
#include "../src/Vertex.hpp"

#include <list>
#include <string>

using namespace std;

class InstanceLoaderTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(InstanceLoaderTest);
    CPPUNIT_TEST(loadingInstanceTest);
    CPPUNIT_TEST_SUITE_END();

    public:
        void loadingInstanceTest() {
            InstanceLoader loader;
            Converter c;
            list<Vertex> v;
            loader.run("data/instances/9.200-40", v);

            auto it = v.begin();

            CPPUNIT_ASSERT(c.convert(it->getValue())    == "AAGGCCGGCT");
            ++it;
            CPPUNIT_ASSERT(c.convert(it->getValue())    == "ACACCCGCCG");
            ++it;
            CPPUNIT_ASSERT(c.convert(it->getValue())    == "ACCAGGGCGT");
            it = --v.end();
            CPPUNIT_ASSERT(c.convert(it->getValue())    == "TTGCCGATCC");
            --it;
            CPPUNIT_ASSERT(c.convert(it->getValue())    == "TTCGCGGGCG");
            --it;
            CPPUNIT_ASSERT(c.convert(it->getValue())    == "TTCCTATGTG");
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(InstanceLoaderTest);
