#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int weight[21];
int memo[21][201];
int n;
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (j == 0)
	{
		return 1;
	}
	if (i == n && j != 0)return 0;
	if (ret != -1) return ret;

	return ret = dp(i + 1, j) + dp(i + 1, j - weight[i]);
}
int main()
{
	int tc, i, sum, el;
	cin >> tc;
	string s;
	stringstream ss;
	getline(cin, s);
	while (tc--)
	{
		getline(cin, s);
		ss.clear();
		ss << s;
		i = 0;
		sum = 0;
		memset(memo, -1, sizeof(memo));
		while (ss >> el) {
			weight[++i] = el;
			sum += el;
		}
		if (sum % 2) cout << "NO\n";
		else
		{
			n = i;
			if (dp(0, sum / 2))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}