#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 3;
long long arr[N];
int main()
{

	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	sort(arr, arr + n);
	long long time = 0;
	for (int i = 0; i < n; ++i)
	{
		time += (arr[i] * x*1ll);
		x = (x <= 1) ? 1 : x - 1;
	}
	printf("%lld\n", time);
	return 0;
}