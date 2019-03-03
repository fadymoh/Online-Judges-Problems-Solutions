#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
string first, second;
const int N = 1024;
int dp[N][N];
int k;

int main()
{

	while (cin >> k , k != 0)
	{
		cin >> first >> second;
		int firstLength = first.length();
		int secondLength = second.length();

		for (int i = 0; i <= firstLength; ++i)
		{
			for (int j = 0; j <= secondLength; ++j)
			{
				dp[i][j] = 0;
				if (i == 0 || j == 0) continue;
				int c = 1;
				while (i - c >= 0 && j - c >= 0 && first[i - c] == second[j - c])
				{
					if (c >= k) dp[i][j] = max(dp[i][j], c + dp[i - c][j - c]);
					++c;
				}
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
			}
		}
		cout << dp[firstLength][secondLength] << endl;
	}
	return 0;
}