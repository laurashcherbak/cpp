#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.1/pr7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestSort)
		{
			const int rowCount = 7;
			const int colCount = 9;

			int** a = new int* [rowCount];
			int** r = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
				r[i] = new int[colCount];
			}

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					a[i][j] = rowCount - i - 1;
					r[i][j] = i;
				}
			}

			Sort(a, rowCount, colCount);

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					Assert::AreEqual(r[i][j], a[i][j]);
				}
			}

			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
				delete[] r[i];
			}
			delete[] a;
			delete[] r;

		}
	};
}
