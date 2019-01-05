#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int l, n;
int length[52];
int memo[52][52];
int dp(int left, int right)
{
	int &ret = memo[left][right];
	if (left + 1 == right) return 0;
	if (ret != -1) return ret;
	int minn = 1000000;
	for (int i = left + 1; i < right; ++i)
		minn = min(minn, dp(left, i) + dp(i, right) + length[right] - length[left]);
	return ret = minn;
}
int main()
{
	while (cin >> l, l != 0)
	{
		cin >> n;
		memset(memo, -1, sizeof(memo));
		length[0] = 0;
		for (int i = 1; i <= n; ++i)
			cin >> length[i];
		length[n + 1] = l;
		cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
	}
	return 0;
}