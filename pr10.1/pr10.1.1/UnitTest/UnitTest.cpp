#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include "../pr8.1/pr8.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCountAndExists)
		{
			char str1[128] = "aSQbQScSQdQSesqqs.";
			//Assert::AreEqual(4, Count(str1));
			Assert::AreEqual(1, Exists(str1));

			char str2[128] = "esqqs.";
			//Assert::AreEqual(0, Count(str2));
			Assert::AreEqual(0, Exists(str2));
		}
	};
}
