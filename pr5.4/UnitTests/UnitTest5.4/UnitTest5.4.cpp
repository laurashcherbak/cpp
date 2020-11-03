#include "pch.h"
#include "CppUnitTest.h"
#include "../../Lab5_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	TEST_CLASS(UnitTest54)
	{
	public:
		
		TEST_METHOD(TestP0)
		{
			double c;
			c = P0(1.0, 19.0);
			Assert::AreEqual(c, 26214.4, 0.1);
		}
	};
}
