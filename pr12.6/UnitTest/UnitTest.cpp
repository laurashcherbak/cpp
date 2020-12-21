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
			Elem* first = NULL,
				* last = NULL,
				* L;
			Elem* Q1_first = NULL,
				* Q1_last = NULL,
				* Q2_first = NULL,
				* Q2_last = NULL;
			Info val;

			for (int i = 0; i < 10; i++)
				Enqueue(first, last, i, true);

			Process(first, Q1_first, Q2_first, Q1_last, Q2_last);

			L = first;
			while (L != NULL)
			{
				val = L->info;
				if ((val % 2) == 0) {
					Assert::AreEqual(Q2_first->info, L->info);
					Q2_first = Q2_first->link;
				}
				else {
					
					Assert::AreEqual(Q1_first->info, L->info);
					Q1_first = Q1_first->link;
				}
				L = L->link; 
			}

		}
	};
}
