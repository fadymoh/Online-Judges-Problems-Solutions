#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int weight[3001], n, m;
int memo[3001][100000];
vector<vector<int>> arr;
bool check()
{
	for (int i = 2; i <= m; ++i)
		if (arr[1].size() <= arr[i].size())
			return false;
	return true;
}
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (check())
	{
		return ret = j;
	}
	if (i > m)
		return ret = 100000;
	if (ret != -1) 
		return ret;
	ret = 100000;
	for (int x = 0; x < arr[i].size(); ++x)
	{
		arr[1].push_back(1);
		int temp = arr[i][x];
		arr[i].erase(arr[i].begin() + x);

		int first = dp(i + 1, j + temp);
		arr[i].push_back(temp);
		arr[1].pop_back();
		int second = dp(i + 1, j);
		ret = min(first, second);
	}
	return ret;
}
int main()
{
	int current = 0, temp, x;
	cin >> n >> m;
	memset(memo, -1, sizeof(memo));
	arr.resize(m+1);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp >> x;
		arr[temp].push_back(x);
	}
	int max = 0;

		max = dp(2, 0);
	
	cout << max << endl;
	system("pause");
	return 0;
}