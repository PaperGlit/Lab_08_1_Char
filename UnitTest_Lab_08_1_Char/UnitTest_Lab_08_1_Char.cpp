#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_Char/Lab_08_1_Char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char* TestChange(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	size_t len = strlen(s);
	while (p = strchr(s + pos1, 'G'))
	{
		if ((s[p - s - 1] == 'O' && s[p - s + 1] == 'O') || (s[p - s - 1] == 'A' && s[p - s + 1] == 'A'))
		{
			pos2 = p - s + 2;
			strncat_s(t, len, s + pos1, pos2 - pos1 - 3);
			strcat_s(t, len, "**");
			pos1 = pos2;
		}
		else
		{
			pos2 = p - s + 1;
			strncat_s(t, len, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}
	strcat_s(t, len, s + pos1);
	strcpy_s(s, len, t);
	return t;
}

namespace UnitTestLab081Char
{
	TEST_CLASS(UnitTestLab081Char)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[101] = "TESTOGOTESTAGA";
			char teststr[101] = "TESTOGOTESTAGA";
			char* dest = Change(str);
			char* testdest = TestChange(teststr);
			Assert::AreEqual(strcmp(dest, testdest), 0);
		}
	};
}
