#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:
		
		TEST_METHOD(TestF)
		{
			int c;
			int nr = -1;
			c = f(255, nr);
			Assert::AreEqual(c, 8);
		}
	};
}
