#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestPushAndPop)
		{
			Elem* top = NULL;
			push(top, 1);
			Assert::AreEqual(1, pop(top));
		}
	};
}
