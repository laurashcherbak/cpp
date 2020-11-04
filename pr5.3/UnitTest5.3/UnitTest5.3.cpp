#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
	TEST_CLASS(UnitTest53)
	{
	public:
		
		TEST_METHOD(TestZ)
		{
			double c;
			c = z(0);
			Assert::AreEqual(c, 1., 0.000001);
		}
	};
}
