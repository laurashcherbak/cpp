#include "pch.h"
#include "CppUnitTest.h"
#include "../pr9.1/pr9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestPercentOfGoodStudent)
		{
			Student* p = new Student[5];
			p[0] = { "Ivanov", 5, ComputerScience, 4, 3, 5 };
			p[1] = { "Petrov", 4, Informatics, 4, 4, 5 };
			p[2] = { "Bulba", 3, MathAndEconomic, 5, 3, 5 };
			p[3] = { "Ivanova", 2, PhysicsAndInformatics, 5, 4, 5 };
			p[4] = { "Petrova", 1, TrudoveNavchannia, 3, 3, 3 };
			Assert::AreEqual(40, PercentOfGoodStudent(p, 5));
		}
	};
}
