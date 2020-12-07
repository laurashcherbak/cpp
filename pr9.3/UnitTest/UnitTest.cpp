#include "pch.h"
#include "CppUnitTest.h"
#include "../pr9.3/pr9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestSortByTitle)
		{


			int N = 5;
			Goods* p = new Goods[N];
			p[0] = { "apple", 10.1, 1, KG };
			p[1] = { "mango", 15.3, 3, Piece };
			p[2] = { "bread", 34.2, 6, Packet };
			p[3] = { "carrot", 4.5, 6, KG };
			p[4] = { "nut", 14.8, 5, Packet };

			Goods* r = new Goods[N];
			r[0] = { "apple", 10.1, 1, KG };
			r[1] = { "bread", 34.2, 6, Packet };
			r[2] = { "carrot", 4.5, 6, KG };
			r[3] = { "mango", 15.3, 3, Piece };
			r[4] = { "nut", 14.8, 5, Packet };


			SortByTitle(p, N);

			for (int i = 0; i < N; i++)
			{
				Assert::AreEqual(p[i].title, r[i].title);
				Assert::AreEqual(p[i].price, r[i].price, 0.01);
				Assert::AreEqual(p[i].amount, r[i].amount);
			}
		}
	};
}
