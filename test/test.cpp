#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1 іт/8.1 іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test81
{
	TEST_CLASS(test81)
	{
	public:

		TEST_METHOD(TestExist_OGO)
		{
			bool result = Exist("xOGOy");
			Assert::IsTrue(result);
		}

		TEST_METHOD(TestExist_AGA)
		{
			bool result = Exist("zAGAz");
			Assert::IsTrue(result);
		}

		TEST_METHOD(TestExist_None)
		{
			bool result = Exist("OGAGO");
			Assert::IsFalse(result);
		}

		TEST_METHOD(TestChange_One)
		{
			char str[101] = "xOGOy";
			char* result = Change(str);
			Assert::AreEqual(0, strcmp(str, "x**y"));
			Assert::AreEqual(0, strcmp(result, "x**y"));
			delete[] result;
		}

		TEST_METHOD(TestChange_Both)
		{
			char str[101] = "AGAOGO";
			char* result = Change(str);
			Assert::AreEqual(0, strcmp(str, "****"));
			delete[] result;
		}

		TEST_METHOD(TestChange_NoTriple)
		{
			char str[101] = "hello";
			char* result = Change(str);
			Assert::AreEqual(0, strcmp(str, "hello"));
			delete[] result;
		}
	};
}