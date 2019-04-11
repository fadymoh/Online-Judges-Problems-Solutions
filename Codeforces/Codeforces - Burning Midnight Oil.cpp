#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;
int n, k;
bool valid(int v)
{
	int linesOfCode = 0;
	int addition = v + v / k;
	int i = 1;
	while (addition)
	{
		linesOfCode += addition;
		++i;
		addition = int((v/pow(k, i)));
	}
	return linesOfCode >= n;
}
int main()
{

	scanf("%d %d", &n, &k);
	long long start = 0, end = 1e9, mid;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (valid(mid)) end = mid;
		else start = mid + 1;
	}
	printf("%d", end);
	return 0;
}