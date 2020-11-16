#include "pch.h"
#include "CppUnitTest.h"
#include "../pr6.1.1/pr6.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestGetSum)
		{
			const int k = 20;
			int a[k] = { 29, 33, 6, 11, -9, 16, 20, 0, -7, 2, -4, 26, 7, 11, 32, 43, 0, 45, 1, 22 };

			Assert::AreEqual(216, GetSum(a, k));
		}

		TEST_METHOD(TestGetAmount)
		{
			const int k = 20;
			int a[k] = { 29, 33, 6, 11, -9, 16, 20, 0, -7, 2, -4, 26, 7, 11, 32, 43, 0, 45, 1, 22 };

			Assert::AreEqual(14, GetAmount(a, k));
		}
	};
}
