#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5_2_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestS)
		{
			double s = 1;
			int n;
			s = S(-0.9, 0.000001, n, s);
			Assert::AreEqual(s, -2.94444, 0.00001);
		}
	};
}
