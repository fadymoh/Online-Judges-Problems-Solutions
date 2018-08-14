#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string temp;
	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		getline(cin, temp);
		bool flag = true;
		stack <char> mStack;
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp[i] == '(' || temp[i] == '[')
				mStack.push(temp[i]);
			else
			{
				if (mStack.empty())
				{
					flag = false;
					break;
				}
				char t = mStack.top();
				if (t == '(' && temp[i] == ')' || t == '[' && temp[i] == ']')
				{
					mStack.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag && mStack.empty())
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}