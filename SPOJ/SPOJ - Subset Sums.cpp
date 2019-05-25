#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
const int N = 2000005;
ll X[N], Y[N];
ll ans;
void calcSubArray(ll a[], ll x[], int n, int c)
{
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		ll sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (mask & (1 << j))
				sum += a[j + c];
		}
		x[mask] = sum;
	}
}
void solveSubsetSum(ll arr[], int n, ll a, ll b)
{
	int firstSize = n / 2;
	int secondSize = n - n / 2;
	calcSubArray(arr, X, firstSize, 0);
	calcSubArray(arr, Y, secondSize, firstSize);
	firstSize = 1 << firstSize;
	secondSize = 1 << secondSize;
	sort(Y, Y + secondSize);

	ll mx = 0;

	for (int mask = 0; mask < firstSize; ++mask)
	{
		auto low = lower_bound(Y, Y + secondSize, a - X[mask]);
		auto high = upper_bound(Y, Y + secondSize, b - X[mask]);
		ans += (high - Y) - (low - Y);
	}
}
int main()
{
	ll n, a, b;
	scanf("%lld %lld %lld", &n, &a, &b);
	ll arr[35];
	for (int i = 0; i < n; ++i)
		scanf("%lld", arr + i);
	solveSubsetSum(arr, n, a, b);
	printf("%lld\n", ans);
	return 0;
}