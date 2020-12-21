#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestEnqueueAndProcess)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			for (int i = 0; i < 3; i++)
				Enqueue(first, last, i);

			int inc_val = 1;
			Process(first, inc_val);

			for (int i = 0; i < 3; i++) {
				Assert::AreEqual(i + 1, first->info);
				first = first->link;
			}

		}
	};
}
