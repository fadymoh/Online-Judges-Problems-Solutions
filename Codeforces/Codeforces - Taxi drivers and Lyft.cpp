#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 6;
int coord[N];
int out[N];
int main()
{
	int n, m, curr;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m + n; ++i)
		scanf("%d", coord + i);
	vector<int> taxi;
	vector<int> rider;
	for (int i = 0; i < m + n; ++i)
	{
		scanf("%d", &curr);
		if (curr) taxi.push_back(i);
		else rider.push_back(i);
	}
	int peoplePtr = 0, maxThreshold;
	for (int i = 0; i < m && peoplePtr < n; ++i)
	{
		int cnt = 0;
		if (i == m - 1) maxThreshold = 1e9;
		else maxThreshold = (coord[taxi[i + 1]] + coord[taxi[i]]) / 2;
		while (peoplePtr < n && coord[rider[peoplePtr]] <= maxThreshold) ++cnt, ++peoplePtr;
		out[i] = cnt;
	}
	for (int i = 0; i < m; ++i)
		printf("%d%c", out[i], " \n"[(i == m - 1)]);
	return 0;
}