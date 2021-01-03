#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/var.h"
#include "../Lab/var.cpp"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Var;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMAX)
		{
#define z 0
			Assert::AreEqual(2, MOD(-2));
			Assert::AreEqual(4, POW(2));
			Assert::AreEqual(1.0, MAX(1, 5, z), 0.001);

		}
	};
}
