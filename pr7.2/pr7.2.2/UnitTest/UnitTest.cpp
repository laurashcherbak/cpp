#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.2/pr7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestSum)
		{
			const int n = 5;

			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = i;

			int s = 0;
			Assert::AreEqual(10, Sum(a, n, 0, 0, s));

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
