#include "pch.h"
#include "CppUnitTest.h"
#include "../pr8.2/pr8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestTrim)
		{
			string str = "  \t Remove  leading    and\ttrailing    spaces   \t\t";
			string res = "Remove leading and trailing spaces";

			Assert::AreEqual(res, Trim(str));
		}
	};
}
