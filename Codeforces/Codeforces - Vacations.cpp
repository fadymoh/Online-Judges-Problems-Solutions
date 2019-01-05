#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[100][3];
	int n, in;
	cin >> n;
	dp[0][0] = 1;
	dp[0][1] = dp[0][2] = 0;

	for (int i = 1; i < n; ++i)
	{
		cin >> in;
		dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = (in == 0 || in == 1) ? 100000 : min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = (in == 0 || in == 2) ? 100000 : min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
	return 0;
}