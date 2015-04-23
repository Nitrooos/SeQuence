#include "../src/app/Instance.hpp"

class InstanceTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(InstanceTest);
    CPPUNIT_TEST(loadingInstance);
    CPPUNIT_TEST_SUITE_END();

    public:
        void loadingInstance() {
            Instance i("data/instances/9.200-40"), j("data/instances/53.500+200");

            CPPUNIT_ASSERT(i.getName() == "data/instances/9.200-40");
            CPPUNIT_ASSERT(i.getNegativeErrors() == 40);
            CPPUNIT_ASSERT(i.getPositiveErrors() ==  0);
            CPPUNIT_ASSERT(i.getOriginalSequenceLength() == 209);

            CPPUNIT_ASSERT(j.getName() == "data/instances/53.500+200");
            CPPUNIT_ASSERT(j.getNegativeErrors() ==   0);
            CPPUNIT_ASSERT(j.getPositiveErrors() == 200);
            CPPUNIT_ASSERT(j.getOriginalSequenceLength() == 509);
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(InstanceTest);
