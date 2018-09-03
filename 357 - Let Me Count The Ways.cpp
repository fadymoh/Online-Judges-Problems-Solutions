#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int coins[5] = { 1, 5, 10, 25, 50 };
int n = 5;
long long memo[6][30001];
long long dp(int type, int value)
{
	long long &ret = memo[type][value];

	if (value == 0)
		return 1;
	if (value < 0 || type == n)
		return 0;

	if (ret != -1) return ret;

	return ret = dp(type + 1, value) + dp(type, value - coins[type]);
}
int main()
{
	memset(memo, -1, sizeof(memo));
	int v;
	while (cin >> v, !cin.eof())
	{
		long long temp = dp(0, v);
		if (temp == 1)
			cout << "There is only 1 way to produce " << v << " cents change.\n";
		else
			cout << "There are " << temp << " ways to produce " << v << " cents change.\n";

	}
	return 0;
}