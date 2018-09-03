#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int memo[21][1 << 20];
vector<pair<int, int>>coor;
int n, k_x, k_y;
int dist(int i, int j)
{
	return abs(coor[i].first - coor[j].first) +
			abs(coor[i].second - coor[j].second);
}
int dp(int i, int mask)
{
	int &ret = memo[i][mask];
	if (ret != -1) return ret;
	if (mask == ((1 << n+1) -1)) 
		return dist(i, 0);
	ret = 10000000;
	for (int j = 0; j <= n; ++j)
		if (!(mask & (1 << j)))
			ret = min(ret, dist(i, j) + dp(j, mask | (1 << j)));
	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(memo, -1, sizeof(memo));
		int x, y;
		cin >> x >> y >> k_x >> k_y >> n;
		coor.clear();
		coor.resize(n+1);
		coor[0] = make_pair(k_x, k_y);
		for (int i = 1; i <= n; ++i)
		{
			int one, two;
			cin >> one >> two;
			coor[i] = make_pair(one, two);
		}
		cout << "The shortest path has length " << dp(0, 1) << endl;
	}
	return 0;
}