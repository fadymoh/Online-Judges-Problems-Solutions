#include <iostream>
#include <algorithm>
using namespace std;
int arr[50001];
int main()
{
	int n, q, temp;
	while (cin >> n, !cin.eof())
	{
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			cin >> temp;
			auto first = lower_bound(arr, arr + n, temp);
			if (first - arr == 0)
			{
				cout << "X ";
				auto second = upper_bound(arr, arr + n, temp);
				if (second - arr == n && *second <= temp)
					cout << "X";
				else
					cout << *second;
			}
			else
			{
				if (first - arr == n && *first >= temp) cout << "X ";
				else cout << *(first - 1) << ' ';
				auto second = upper_bound(arr, arr + n, temp);
				if (second - arr == n && *second <= temp)
					cout << "X";
				else
					cout << *second;
			}
			cout << endl;
		}
	}
	return 0;
}