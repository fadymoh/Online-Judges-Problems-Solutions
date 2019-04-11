#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
long long n, m;
vector<int> woodHeight;

bool valid(int height)
{
	long long currentCut = 0;
	for (int i = 0; i < n; ++i)
		if (woodHeight[i] > height) currentCut += (woodHeight[i] - height);
	return currentCut >= m;
}
int main()
{
	scanf("%d %d", &n, &m);
	woodHeight.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &woodHeight[i]);
	int start = 0, end = 2000000000, mid;
	while (start < end)
	{
		mid = start + (end - start + 1) / 2;
		if (valid(mid)) start = mid;
		else end = mid - 1;
	}
	printf("%d\n",start);
	return 0;
}