#include "pch.h"
#include "CppUnitTest.h"
#include "../pr6.4/pr6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestArrays)
		{
			const int k = 10;
			double a[k] = { 0, 0.1, -4.3, 0, -4.2, 5, 0, 6.5, 6.5, 0 };
			double r[k] = { 0, 0, 0, 0, 0.1, -4.3, -4.2, 5, 6.5, 6.5 };

			RearrangementArray(a, k);

			for (int i = 0; i < k; i++) {
				Assert::AreEqual(r[i], a[i]);
			}
		}

		TEST_METHOD(TestGetSumPositiveValues)
		{
			const int k = 5;
			double a[k] = { 0, 8.7, -0.4, 0, 6.9 };
			Assert::AreEqual(8.3, GetSumPositiveValues(a, 0, k - 1), 0.1);

		}

	};
}
