#include "pch.h"
#include "CppUnitTest.h"
#include "../pr8.2/pr8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestGetCountWords)
		{
			string str = "Find the shortest word";

			Assert::AreEqual(4, GetCountWords(str));
		}
	};
}
