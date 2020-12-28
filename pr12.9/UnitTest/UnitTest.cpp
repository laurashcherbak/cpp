#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestSum)
		{

			int N = 3;
			Info value;
			Node* root1 = NULL;

			for (int i = 1; i <= N; i++) {
				value = i;
				root1 = Insert(root1, value);
			}
			Assert::AreEqual(6, Sum(root1));

			value = 4;
			root1 = Insert(root1, value);
			Assert::AreEqual(10, Sum(root1));

		}
	};
}
