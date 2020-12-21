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
			Elem* F;

			F = L;
			Enqueue(L, F, 0, 10, 0, true);

			F = L;
			Process(L, L1, L2, F);

			//F = L;
			for (int i = 1; i <= 10; i++) {
				if (((i % 2) == 0)) {
					Assert::AreEqual((i), L1->info);
					L1 = L1->link;
				}
				else {
					Assert::AreEqual(-i, L2->info);
					L2 = L2->link;
				}
				//L = L->link;
			}

		}
	};
}
