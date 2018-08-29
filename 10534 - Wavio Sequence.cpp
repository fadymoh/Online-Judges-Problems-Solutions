#include <iostream>
#include <algorithm>
using namespace std;
int l[10001];
int a[10001];
int lis_arr[10001];
int lds_arr[10001];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n, !cin.eof())
	{

		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int lis = 0, lds = 0;
		for (int i = 0; i < n; ++i)
		{
			int x = a[i];

			int ind = lower_bound(l, l + lis, x) - l;
			l[ind] = x;
			if (ind + 1 >= lis)
				lis = ind + 1;
			lis_arr[i] = ind + 1;
		}
		for (int i = n - 1; i >= 0; --i)
		{
			int x = a[i];

			int ind = lower_bound(l, l + lds, x) - l;
			l[ind] = x;
			if (ind + 1 >= lds)
				lds = ind + 1;
			lds_arr[i] = ind + 1;
		}
		int ans = 1;
		for (int i = 0; i < n; ++i)
		{
			ans = max(ans, 2 * min(lis_arr[i], lds_arr[i]) - 1);
		}

		cout << ans << endl;
	}
	system("pause");
	return 0;
}