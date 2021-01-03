#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/sum.h"
#include "../Lab/var.h"
#include "../Lab/add.h"
#include "../Lab/var.cpp"
#include "../Lab/sum.cpp"
#include "../Lab/add.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Var;
using namespace Sum;
using namespace Add;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestSum)
		{
			n = 0;
			s = 0;
			x = -0.20;
			eps = 0.0000001;
			Sum::Sum();
			Assert::AreEqual(0.18232, s, 0.00001);
		}
	};
}
