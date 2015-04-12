#include "../src/InstanceLoader.hpp"
#include "../src/Vertex.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class InstanceLoaderTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(InstanceLoaderTest);
    CPPUNIT_TEST(loadingInstanceTest);
    CPPUNIT_TEST(commonPartTest);
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

        void commonPartTest() {
            InstanceLoader loader;
            Converter c;

            vector<string>  sequences({"AAGGCCGGCT", "AGGCCGGCTA", "GCCGGCTACT", "GGCTACTGCG",
                "TACTGCGTTC", "ACTGCGTTCG"});
            vector<int>     goodResults({9, 8, 7, 7, 9});
            vector<Vertex*> vertexes(sequences.size());

            for (int i = 0; i < vertexes.size(); ++i)
                vertexes[i] = new Vertex(c.convert(sequences[i]));

            for (int i = 0; i < vertexes.size() - 1; ++i)
                CPPUNIT_ASSERT(loader.commonPart(*vertexes[i], *vertexes[i + 1]) == goodResults[i]);

            for (auto ptr : vertexes)
                delete ptr;
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(InstanceLoaderTest);
