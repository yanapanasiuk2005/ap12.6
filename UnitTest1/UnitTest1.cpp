#include "pch.h"
#include "CppUnitTest.h"
#include <cassert>
#include "../ap12.6/ap12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Elem* first = NULL,
                * last = NULL;

            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);

            int valueToFind1 = 2;
            assert(contains(first, valueToFind1));

            int valueToFind2 = 4;
            assert(!contains(first, valueToFind2));

            enqueue(first, last, valueToFind2);
            assert(contains(first, valueToFind2));

            clearQueue(first, last);
        }

    };
}
