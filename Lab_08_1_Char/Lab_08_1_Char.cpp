#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1 + 1, 'G'))
	{
		if ((s[p - s - 1] && s[p - s + 1] == 'O') || (s[p - s - 1] && s[p - s + 1] == 'A'))
		{
			pos2 = p - s + 2;
			strncat(t, s + pos1, pos2 - pos1 - 3);
			strcat(t, "**");
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
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