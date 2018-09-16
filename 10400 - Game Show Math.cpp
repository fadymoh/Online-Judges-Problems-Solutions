#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n, arr[101], val, opr[101];
bool memo[101][64001];
bool dp(int i, int sum)
{
	bool &ret = memo[i][sum + 32000];
	if (sum >= 32000 || sum <= -32000) return false;
	if (sum == val && i == n) return true;
	if (i >= n) return false;
	if (ret) return false;
	ret = true;
	opr[i] = 0;
	if (dp(i + 1, sum + arr[i])) return true;
	opr[i] = 1;
	if (dp(i + 1, sum - arr[i])) return true;
	opr[i] = 2;
	if (dp(i + 1, sum * arr[i])) return true;
	opr[i] = 3;
	if (sum % arr[i] == 0 && dp(i + 1, sum / arr[i])) return true;
	return false;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(memo, 0, sizeof memo);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cin >> val;
		if (dp(1, arr[0]))
		{
			for (int i = 0; i < n; ++i)
			{
				cout << arr[i];
				if (i != n - 1) {
					if (opr[i] == 0) cout << '+';
					else if (opr[i] == 1) cout << '-';
					else if (opr[i] == 2) cout << '*';
					else if (opr[i] == 3) cout << '/';
				}
			}
			cout << '=' << val;
		}
		else cout << "NO EXPRESSION";
		cout << endl;
	}
	return 0;
}