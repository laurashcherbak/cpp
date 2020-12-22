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
				* last = NULL;
			Elem* L1 = NULL,
				* L2 = NULL;

			string str = "1 2 3 4 5 6";
			SplitStrAndPutIntoQueue(first, last, str);

			Assert::AreEqual(6, Count(first));

			Info val = "0";
			int N = 3;
			Process(first, L1, L2, N, val);

			Assert::AreEqual(4, Count(L1));
			Assert::AreEqual(4, Count(L2));

			int i = 1;
			while (first != NULL)
			{
				if (i < N) {
					Assert::AreEqual(L1->info, first->info);
					L1 = L1->next;
				}
				else if (i == N) {
					Assert::AreEqual(L1->info, first->info);
					L1 = L1->next;
					Assert::AreEqual(L1->info, val);
					L1 = L1->next;
					Assert::AreEqual(L2->info, val);
					L2 = L2->next;
				}
				else {
					Assert::AreEqual(L2->info, first->info);
					L2 = L2->next;
				}
				first = first->next;
				i++;
			}

		}
	};
}
