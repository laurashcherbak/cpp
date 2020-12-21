#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestProcess)
		{
			Elem* L = NULL;
			Elem* L1 = NULL;
			Elem* L2 = NULL;
			for (int i = 0; i < 5; i++)
				Enqueue(L, (i % 2 == 0 ? i : -i), false);

			Process(L, L1, L2);

			for (int i = 0; i < 5; i++) {
				if (i % 2 == 0) {
					Assert::AreEqual(i, L1->info);
					L1 = L1->link;
				}
				else {
					Assert::AreEqual(-i, L2->info);
					L2 = L2->link;
				}
			}

		}
	};
}
