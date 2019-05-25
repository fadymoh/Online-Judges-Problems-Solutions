#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
const int N = 2000 + 3;
#define min(x,y) ((x) < (y) ? (x) : (y))

bool comp(const int& a, const int& b)
{
	return a > b;
}
int main()
{
	int n, curr;
	scanf("%d", &n);
	long long sum = 0;
	int odd[N], even[N];
	int oddPtr = 0, evenPtr = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		sum += curr;
		if (curr & 1) odd[oddPtr++] = curr;
		else even[evenPtr++] = curr;
	}
	sort(odd, odd + oddPtr, comp);
	sort(even, even + evenPtr, comp);
	int maxDeletedElements = min(evenPtr, oddPtr);
	sum -= accumulate(odd, odd + maxDeletedElements, 0);
	sum -= accumulate(even, even + maxDeletedElements, 0);
	if (evenPtr > maxDeletedElements) sum -= even[maxDeletedElements];
	else if (oddPtr > maxDeletedElements) sum -= odd[maxDeletedElements];

	printf("%lld\n", sum);
	return 0;
}