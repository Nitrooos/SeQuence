#include "../src/InstanceLoader.hpp"
#include "../src/Vertex.hpp"

#include <vector>
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
            vector<Vertex> v;
            loader.run("data/instances/9.200-40", v);

            CPPUNIT_ASSERT(c.convert(v[0].getValue())               == "AAGGCCGGCT");
            CPPUNIT_ASSERT(c.convert(v[1].getValue())               == "ACACCCGCCG");
            CPPUNIT_ASSERT(c.convert(v[2].getValue())               == "ACCAGGGCGT");
            CPPUNIT_ASSERT(c.convert(v[v.size() - 3].getValue())    == "TTCCTATGTG");
            CPPUNIT_ASSERT(c.convert(v[v.size() - 2].getValue())    == "TTCGCGGGCG");
            CPPUNIT_ASSERT(c.convert(v.back().getValue())           == "TTGCCGATCC");
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(InstanceLoaderTest);
