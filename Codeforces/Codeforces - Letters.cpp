#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long  n, m, query, temp;
	cin >> n >> m;
	long  arr[200002];
	arr[0] = 0;
	cin >> arr[1];
	for (int i = 2; i <= n; ++i)
	{
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}

	sort(arr, arr + n);
	for (int i = 0; i < m; ++i)
	{
		cin >> query;
		auto it = lower_bound(arr, arr + n, query);
		long  dorm_size = ((arr[(it - arr)]) - arr[(it - arr - 1)]);
		query -= arr[it - arr - 1];
		cout << (it - arr) << ' ' << query << endl;
	}
	return 0;
}