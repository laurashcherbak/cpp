#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestProcess)
		{
			Elem* first = NULL,
				* last = NULL;
			Elem* res_first = NULL,
				* res_last = NULL;

			string str;
				
			str = "52b3 15 37 8ba 8ab";
			SplitStrAndPutIntoQueue(first, last, str);

			str = "15 52b3 37 8ab 8ba";
			SplitStrAndPutIntoQueue(res_first, res_last, str);

			Process(first, last);

			Assert::AreEqual(5, Count(first));

			while (first != NULL)
			{
				Assert::AreEqual(res_first->info, first->info);
				first = first->link;
				res_first = res_first->link;
			}
		}
	};
}
