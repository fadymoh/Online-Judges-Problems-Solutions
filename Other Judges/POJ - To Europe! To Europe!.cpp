#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;
int b, l, n;
int speed[1003], weight[1003];

double dp[1003];
int vis[1003];
double solve(int ind)
{
	double &ret = dp[ind];
	if (ind == n) return 0;
	if (vis[ind]) return ret;
	ret = 1e9;
	int mnSpeed = 1e9;
	int sumW = 0;
	vis[ind] = true;
	for (int i = ind; i < n; ++i)
	{
		mnSpeed = min(mnSpeed, speed[i]);
		sumW += weight[i];
		if (sumW > b) break;
		ret = min(ret, 1. * l / mnSpeed + solve(i + 1));
	}
	return ret;
}
int main()
{
	while (cin >> b >> l >> n, b != 0 && l != 0, n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> weight[i] >> speed[i];
		}
		memset(vis, 0, sizeof vis);
		cout << setprecision(1) << fixed <<solve(0) * 60 << endl;
	}
	return 0;
}