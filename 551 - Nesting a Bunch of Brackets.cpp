#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	char x;
	char in[3001];
	unordered_map <char, char> brackets;
	brackets[')'] = '(';
	brackets[']'] = '[';
	brackets['}'] = '{';
	brackets['>'] = '<';
	brackets['q'] = 'p';

	while (gets_s(in), !cin.eof())
	{
		stack <char> s;
		vector<pair<char, int>> mArr;
		int size = strlen(in);
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			count++;
			char c = in[i];
			if (!(c != '(' && c != '[' && c != '{' && c != '<'
				&& c != ')' && c != ']' && c != '}' && c != '>'))
				mArr.push_back(make_pair(c, count));
			if (c == '*' && i != 0 && in[i - 1] == '(')
				mArr.pop_back(), mArr.push_back(make_pair('p',--count));
			else if (c == '*' && i != size - 1 && in[i + 1] == ')')
				mArr.push_back(make_pair('q', count)), ++i;
		}
		int i = 0;
		bool err = false;
		for (; i < mArr.size(); ++i)
		{
			char c = mArr[i].first;
			if (c == '(' || c == '[' || c == '{' || c == '<'
				|| c == 'p')
				s.push(c);
			else {
				if (s.empty() || brackets[c] != s.top()) {
					err = true;
					break;
				}
				s.pop();
			}
		}
		if (err || !s.empty())
		{
			if (!s.empty())
				--i;
			cout << "NO " << mArr[i].second << endl;
		}
		else cout << "YES\n";
	}
	return 0;
}