﻿#include <iostream>
using namespace std;

char* Change(char* s)
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

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}