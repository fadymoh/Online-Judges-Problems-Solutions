#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin.ignore();
	while (n--)
	{
		stack <char> mStack;
		string x;
		getline(cin, x);
		bool flag = false;
		for (int i = 0; i < x.length(); ++i)
		{
			if (x[i] == '(' || x[i] == '[') mStack.push(x[i]);
			else if (!mStack.empty() && ((x[i] == ')' && mStack.top() == '(') || (x[i] == ']' && mStack.top() == '['))) 
				mStack.pop();
			else {
				flag = true;
				break;
			}
		}
		if (flag || !mStack.empty()) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}