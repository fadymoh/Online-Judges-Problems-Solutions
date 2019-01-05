#include <iostream>
#include <algorithm>
using namespace std;
#define EPS 1e-18
int main()
{
	int n, u;
	cin >> n >> u;
	int arr[100010] = { 0 };
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	double ans = 0;
	bool exists = false;
	for (int i = 0; i < n; ++i)
	{
		int l = i + 1, r = n - 1;
		int can = -1;
		while (l <= r)
		{
			int mid = l + (r - l + 1) / 2;
			if (arr[mid] - arr[i] <= u)
			{
				can = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		if (can == -1 || can == i + 1) continue;
		if ((1.0*(arr[can] - arr[i + 1]) / (arr[can] - arr[i]) - ans) > EPS)
			ans = 1.0*(arr[can] - arr[i + 1]) / (arr[can] - arr[i]);
		exists = true;
	}
	if (exists)
		printf("%.10lf\n", ans);

	else cout << -1 << endl;
	return 0;
}