#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
const int N = 2000005;
ll  X[N], Y[N];
int mod;
void calcSubArray(ll a[], ll x[], int n, int c)
{
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		ll sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (mask & (1 << j))
				sum = (sum + a[j + c]) % mod;
		}
		x[mask] = sum;
	}
}
ll solveSubsetSum(ll a[], int n)
{
	int firstSize = n / 2;
	int secondSize = n - n / 2;
	calcSubArray(a, X, firstSize, 0);
	calcSubArray(a, Y, secondSize, firstSize);
	firstSize = 1 << firstSize;
	secondSize = 1 << secondSize;
	sort(Y, Y + secondSize);
	int ans = 0;
	for (int mask = 0; mask < firstSize; ++mask)
	{
		int rem = (mod - X[mask]) % mod;
		auto low = lower_bound(Y, Y + secondSize, rem);
		auto high = upper_bound(Y, Y + secondSize, rem);
		ans += (high - Y) - (low - Y);
	}
	return ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		scanf("%d %d", &n, &mod);
		ll a[40];
		for (int i = 0; i < n; ++i)
			scanf("%lld", a + i);
		printf("%lld\n", solveSubsetSum(a, n));
	}

	return 0;
}