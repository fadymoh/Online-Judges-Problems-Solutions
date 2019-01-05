#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
long long arr[201];
int memo[201][201][15];
int n, q, m, d;
int dp(int pos, int remM, int sum)
{
	if (remM == 0 && sum == 0) return 1;
	if (remM == 0 && sum != 0) return 0;
	if (pos >= n) return 0;
	if (remM < 0) return 0;
	int &ret = memo[pos][sum][remM];
	if (ret != -1) return ret;
	ret = dp(pos + 1, remM - 1, (sum + arr[pos]) % d) + dp(pos + 1, remM, sum%d);

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int set_counter = 0;
	while (cin >> n >> q, n != 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << "SET " << ++set_counter << ":\n";
		int query_counter = 0;
		for (int i = 0; i < q; ++i)
		{
			memset(memo, -1, sizeof(memo));
			cin >> d >> m;
			cout << "QUERY " << ++query_counter << ": " << dp(0, m, 0) << endl;
		}
	}

	system("pause");
	return 0;
}