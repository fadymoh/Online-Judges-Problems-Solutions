#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, t;
int memo[10001];
bool flag = false;
int maxx = -1;
int minn = 100000;
bool visited[10001];
void check(int val)
{
	if (visited[val]) return;
	visited[val] = true;
	if (val >= t) return;
	check(val + n);
	check(val + m);
}
int dp(int rem)
{
	int &ret = memo[rem];
	if (rem < 0) return -100000;
	if (rem == 0) return 0;
	if (ret != -1) return ret;
	return ret = max(1 + dp(rem - n), 1 + dp(rem - m));
}
int main()
{
	while (cin >> n >> m >> t, !cin.eof())
	{
		memset(memo, -1, sizeof memo);
		memset(visited, 0, sizeof visited);
		check(0);
		if (visited[t]) cout << dp(t)<< endl;
		else
		{
			int temp = t;
			while (!visited[--temp]);
			cout << dp(temp) << ' ' << t - temp << endl;
		}
	}
}