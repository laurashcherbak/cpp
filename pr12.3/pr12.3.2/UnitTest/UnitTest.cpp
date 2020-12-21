#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestEnqueueAndProcess)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			for (int i = 0; i < 3; i++)
				Enqueue(first, last, i + 1, 0);

			int V1 = 3;
			int V2 = 4;
			Process(first, V1, V2);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(i + 1, first->info);
				first = first->next;
			}

		}
	};
}
