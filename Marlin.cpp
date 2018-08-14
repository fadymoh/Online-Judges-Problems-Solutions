#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;
bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	const int y = k;
	char arr[4][200];
	bool flag = false;
	int row = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = '.';
	while (k != 0)
	{
		if (k - (n - 2) >= 0)
		{
			for (int j = 1; j < n - 1; ++j)
				arr[row][j] = '#';
		}
		else
		{

		}
	}


	system("pause");
	return 0;
}