#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include "../pr11.1/pr11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCheckStringIsDoubleAndNotEqualsSinX)
		{
			Assert::AreEqual(2.5, CheckStringIsDoubleAndNotEqualsSinX("2.5"), 0.001);
			Assert::AreEqual(NULL, CheckStringIsDoubleAndNotEqualsSinX("1.0"), 0.001);
			Assert::AreEqual(NULL, CheckStringIsDoubleAndNotEqualsSinX("0.5"), 0.001);
			Assert::AreEqual(NULL, CheckStringIsDoubleAndNotEqualsSinX("0."), 0.001);
			Assert::AreEqual(NULL, CheckStringIsDoubleAndNotEqualsSinX("-0.5"), 0.001);
			Assert::AreEqual(NULL, CheckStringIsDoubleAndNotEqualsSinX("-1.0"), 0.001);
			Assert::AreEqual(-1.5, CheckStringIsDoubleAndNotEqualsSinX("-1.5"), 0.001);
		}
	};
}
