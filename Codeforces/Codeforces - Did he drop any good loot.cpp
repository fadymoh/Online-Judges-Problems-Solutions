#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n, m;
int price[10005];
int weight[10005];
int extra[10005];
int indices[10005];
int dp[10005][705][3];
int solve(int ind, int limit, int activate)
{
	if (limit == 0) return 0;
	if (ind == n) return 0;
	int indx = indices[ind];
	int ch1 = solve(ind + 1, limit, activate), ch2 = 0;
	int &ret = dp[indx][limit][activate];
	if (~ret) return ret;
	int nlimit = (activate < 2) ? limit + extra[indx] : limit;
	if (nlimit - weight[indx] >= 0)
		ch2 = price[indx] + solve(ind + 1, nlimit - weight[indx], min(2, activate + 1));
	return ret = max(ch1, ch2);
}
int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; ++i)
		cin >> price[i] >> weight[i] >> extra[i];
	iota(indices, indices + n, 0);
	sort(indices, indices + n, [](int i, int j)
	{
		if (extra[i] != extra[j])
			return extra[i] > extra[j]; // descending
		if (weight[i] != weight[j])
			return weight[i] > weight[j];
		return price[i] > price[j];
	});
	cout << solve(0, m, 0) << endl;
	return 0;
}