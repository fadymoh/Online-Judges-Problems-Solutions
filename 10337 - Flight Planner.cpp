#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int x;
int arr[10][1001];
int memo[10][1001];
int dp(int alt, int milage)
{
	int &ret = memo[alt][milage];
	if (alt < 0 || alt > 9) return 100000;
	if (ret != -1)
		return ret;
	if (milage == x / 100)
		if (alt == 0) return 0;
		else return 100000;
	return ret = min(dp(alt + 1, milage + 1) + 60 - arr[alt][milage],
		min(dp(alt, milage + 1)  + 30 - arr[alt][milage],
			dp(alt - 1, milage + 1) + 20 - arr[alt][milage]));
}
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		cin >> x;
		int rows = x / 100;
		memset(memo, -1, sizeof memo);
		for (int i = 9; i >=0; --i)
		{
			for (int j = 0; j < rows; ++j)
				cin >> arr[i][j];
		}
		cout << dp(0, 0) << endl << endl;

	}
	return 0;
}