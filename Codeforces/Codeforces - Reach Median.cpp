#include <iostream>
#include <algorithm>
using namespace std;
long long arr[2 * 1000000];
int main()
{
	long long n, s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	if (s < arr[n / 2])
	{
		long long ans = 0;
		for (long long i = 0; i <= n / 2; ++i)
		{
			if (arr[i] > s)
				ans += abs(arr[i] - s);
		}
		cout << ans << endl;
	}
	else
	{
		long long ans = 0;
		for (long long i = n / 2; i < n; ++i)
		{
			if (arr[i] < s)
				ans += abs(arr[i] - s);
		}
		cout << ans;
	}
	return 0;
}