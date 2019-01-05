#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double error = 1E-6;
int tc, m, s, c, t;
vector<pair<int, int>> coins;
int memo[41][301][301];
int dp(int i, int c, int it)
{
	if (i == m || c*c + it*it > pow(s,2)) return 1000000;
	if (c*c + it*it ==  pow(s, 2)) 
		return 0;
	int &ret = memo[i][c][it];
	if (ret != -1) return ret;
	return ret = min(dp(i + 1, c, it), 1 + dp(i, c + coins[i].first, it + coins[i].second));
}
int main()
{
	cin >> tc;
	while (tc--)
	{
		cin >> m >> s;
		memset(memo, -1, sizeof(memo));
		coins.resize(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> c >> t;
			coins[i] = make_pair(c, t);
			x[i] = 0;
		}
		int temp = dp(0, 0, 0);
		if (temp > 301) cout << "not possible\n";
		else cout << temp << endl;
		if (tc)cin.ignore();
	}
	return 0;
}