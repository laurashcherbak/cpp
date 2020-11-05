#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51
{
	TEST_CLASS(UnitTest51)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double c;
			c = g(1.0, 1.0);
			Assert::AreEqual(c, 0.158529, 0.000001);
		}
	};
}
