#include "pch.h"
#include "CppUnitTest.h"
#include "../pr6.2.2/pr6.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestArrays)
		{
			const int n = 10;
			int a[n] = { -6, 2, -5, 6, 3, 4, 3, 5, 7, 10 };
			int r[n] = { 10, 2, -5, 6, 3, 4, 3, 5, 7, -6 };

			SwapMinMaxInArray(a, n, 0, 0, 0);

			for (int i = 0; i < n; i++) {
				Assert::AreEqual(r[i], a[i]);
			}
		}
	};
}
