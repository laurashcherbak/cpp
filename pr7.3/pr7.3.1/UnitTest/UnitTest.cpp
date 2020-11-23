#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.3/pr7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestPart1_Sum)
		{
			const int rowCount = 3;
			const int colCount = 3;


			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					a[i][j] = -i;
				}
			}

			int s;
			s = Part1_Sum(a, rowCount, colCount);
			Assert::AreEqual(s, -9);

			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;

		}
	};
}
