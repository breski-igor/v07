#include "CppUnitTest.h"
#include "..\app\money.h"
#include <string> 
using namespace std::string_literals;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TotalCents)
		{
			money m1(2, 50);
			Assert::AreEqual(250, m1.get_total());
			money m2(0, 50);
			Assert::AreEqual(50, m2.get_total());
			money m3(50, 0);
			Assert::AreEqual(5000, m3.get_total());
			money m4(-3, -20);
			Assert::AreEqual(-320, m4.get_total());
			money m5(-3, 20);
			Assert::AreEqual(-280, m5.get_total());
			money m6(3, -20);
			Assert::AreEqual(280, m6.get_total());
			money m7(1, 101);
			Assert::AreEqual(201, m7.get_total());
			money m8(-1, -101);
			Assert::AreEqual(-201, m8.get_total());
		}
		TEST_METHOD(AddCents)
		{
			money m1(1, 11);
			money m2(6, 85);
			m1 += m2;
			Assert::AreEqual(796, m1.get_total());


			money m3(-1, -11);
			money m4(6, 85);
			m3 += m4;
			Assert::AreEqual(574, m3.get_total());
		}


		TEST_METHOD(SubtractCents)
		{
			money m1(1, 11);
			money m2(6, 85);
			m1 -= m2;
			Assert::AreEqual(-574, m1.get_total());

			money m3(-1, -11);
			money m4(6, 85);
			m3 -= m4;
			Assert::AreEqual(-796, m3.get_total());
		}


		TEST_METHOD(testOutput)
		{
			money m1(1, 10);
			money m2(2, 95);
			m1 += m2;
			std::stringstream ss1;
			ss1 << m1;
			Assert::AreEqual("4 eur 05 ct"s, ss1.str());

			money m3(1, 10);
			money m4(1, 10);
			m3 -= m4;
			std::stringstream ss2;
			ss2 << m3;
			Assert::AreEqual("0 eur 00 ct"s, ss2.str());

			money m5(-1, -10);
			money m6(1, 10);
			m5 -= m6;
			std::stringstream ss3;
			ss3 << m5;
			Assert::AreEqual("-2 eur 20 ct"s, ss3.str());
		}

	};
}
