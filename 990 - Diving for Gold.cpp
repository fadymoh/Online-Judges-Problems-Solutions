#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int memo[31][1001];
bool path[31][1001];
int t, w, n, temp_d, temp_g, cnt;
int p[31];
int v[31];
int d[31];
int x[31];
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == n) return ret = 0;
	return ret = (j < p[i]) ? dp(i + 1, j) : max(dp(i + 1, j), v[i] + dp(i + 1, j - p[i]));
}
void print(int i, int j)
{
	if (i == n) return;
	if (memo[i][j] > memo[i + 1][j])
	{
		x[i] = true;
		++cnt;
		return print(i + 1, j - p[i]);
	}
	return print(i + 1, j);
}

int main()
{
	bool first = true;
	while (scanf("%d%d", &t, &w) == 2) {
		if (!first) {
			puts("");
		}

		first = false;
		scanf("%d", &n);
		memset(memo, -1, sizeof(memo[0][0]) * 31 * 1001);
		cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp_d >> v[i];
			d[i] = temp_d;
			p[i] = 3 * w * temp_d;
			x[i] = 0;
		}
		cout << dp(0, t) << endl;
		print(0, t);
		cout << cnt << endl;
		for (auto i = 0; i < n; ++i)
			if (x[i])
				cout << d[i] << ' ' << v[i] << endl;
	}
	system("pause");
	return 0;
}