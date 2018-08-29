#include <iostream>
#include <string>
using namespace std;
int l, n, global;
string temp;
bool isValid(int len, string str)
{
	int len_half = len / 2; 

	for (int patternLen = 1; patternLen <= len_half; ++patternLen) {
		bool flag = false;

		for (int i = 0; i < patternLen; ++i) {
			if (str[len - 1 - i] != str[len - 1 - i - patternLen]) {
				flag = true;
				break;
			}
		}

		if (!flag) return false;
	}
	return true;
}
bool backtrack(int index, string current)
{
	if (!isValid(index, current)) return false;

	if (global == n)
	{
		for (int i = 0; i < current.length(); ++i)
		{
			if (i % 4 == 0 && i != 0)
				cout <<((i == 4*16)? '\n': ' ');
			cout << current[i];
		}
		cout << endl << current.length() << endl;
		return true;
	}
	++global;
	for (int i = 0; i < temp.length(); ++i)
	{
		if (backtrack(index + 1, current + temp[i]))
			return true;
	}
	return false;
}
int main()
{
	while (cin >> n, n != 0)
	{
		cin >> l;
		global = 0;
		temp = "";
		for (int i = 0; i < l; ++i)
			temp += char(65 + i);
		backtrack(0,"");
	}
	system("pause");
	return 0;
}