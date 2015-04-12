#include "../src/Helpers.hpp"

class HelpersTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(HelpersTest);
    CPPUNIT_TEST(get);
    CPPUNIT_TEST_SUITE_END();

    public:
        void get() {
            Converter c;

            vector<string>  sequences({"AAGGCCGGCT", "AGGCCGGCTA", "GCCGGCTACT", "GGCTACTGCG",
                "TACTGCGTTC", "ACTGCGTTCG"});
            vector<int>     goodResults({9, 8, 7, 7, 9});
            vector<Vertex*> vertexes(sequences.size());

            for (int i = 0; i < vertexes.size(); ++i)
                vertexes[i] = new Vertex(c.convert(sequences[i]));

            for (int i = 0; i < vertexes.size() - 1; ++i)
                CPPUNIT_ASSERT(CommonPart::get(*vertexes[i], *vertexes[i + 1]) == goodResults[i]);

            for (auto ptr : vertexes)
                delete ptr;
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(HelpersTest);
