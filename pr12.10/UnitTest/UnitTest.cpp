#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestFind)
		{

			int N = 3;
			Info value;
			Node* root = NULL;
			Node* tmp = NULL;

			for (int i = 1; i <= N; i++) {
				value = i;
				root = Insert(root, value);
			}
			Assert::AreEqual(value, Find(root, value)->info);//Get and check last value

			value = 1;
			Assert::AreEqual(value, Find(root, value)->info);//Get and check first value
		}
	};
}
