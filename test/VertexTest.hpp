#include "../src/Vertex.hpp"
#include "../src/Converter.hpp"

#include <time.h>

class VertexTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(VertexTest);
    CPPUNIT_TEST(addingSuccessors);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() {
            srand((unsigned)time(NULL));
        }

        void addingSuccessors() {
            Converter c;
            Vertex v(c.convert("ACTGGCTAGG"));

            for (int i = 0; i < 100; ++i)
                v.addSuccessor(nullptr, rand()%10);

            int prev = 10;
            for (auto &s : v.getSuccessors()) {
                CPPUNIT_ASSERT(s.second <= prev);
                prev = s.second;
            }
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(VertexTest);
