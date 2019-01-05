#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
double arr[9][9];
int n;
double maxxx;
double memo[11][1 << 10];
int output[11][1 << 10];
double dp(int i, int mask)
{
	double &ret = memo[i][mask];
	if (ret != 1000000) return ret;
	if (mask == (1 << n) - 1)
	{
		return 0;
	}
	double temp = 1000000;
	int temp_pos = -1;
	for (int j = 0; j < n; ++j)
		if (!(mask & (1 << j)))
		{
			double  x = arr[i][j] + dp(j, mask | (1 << j));
			if (x < temp)
			{
				temp = x;
				temp_pos = j;
			}
		}
	output[i][mask] = temp_pos;
	return ret = temp;
}
int main()
{
	int tc = 1;
	while (cin >> n, n != 0)
	{
		printf("**********************************************************\n");
		printf("Network #%d\n", tc++);
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < (1 << 10); ++j)
				memo[i][j] = 1000000;
		vector <pair<int, int>> coordinates(n);
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			coordinates[i] = make_pair(x, y);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j) arr[i][j] = 0;
				else arr[i][j] = sqrt(pow(abs(coordinates[i].first - coordinates[j].first), 2)
					+ pow(abs(coordinates[i].second - coordinates[j].second), 2));
			}
		}
		double minnnn = 100000;
		int idx = 0;
		for (int i = 0; i < n; ++i)
		{
			double out = dp(i, (1<<i)) + 16 * (n - 1);
			if (minnnn > out)
			{
				minnnn = out;
				idx = i;
			}
		}
		int bitset = 0;
		for (int i = 0; i < n-1; ++i) {
			bitset |= (1 << idx);
	
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", coordinates[idx].first,
				coordinates[idx].second, coordinates[output[idx][bitset]].first, coordinates[output[idx][bitset]].second
				, arr[idx][output[idx][bitset]] + 16);

			idx = output[idx][bitset];
		}
		printf("Number of feet of cable required is %.2lf.\n", minnnn);

	}
	return 0;
}