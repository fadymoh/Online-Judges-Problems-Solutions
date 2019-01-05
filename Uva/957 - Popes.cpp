#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
	int y, p;
	while (cin >> y, !cin.eof())
	{
		cin >> p;
		for (int i = 0; i < p; ++i)
			cin >> arr[i];
		int maxx = -1, start = 0, end = 0;
		for (int i = 0; i < p; ++i)
		{
			auto lower = upper_bound(arr, arr + p, arr[i] + y - 1);
			if (maxx < (lower - arr - i))
			{
				maxx = lower - arr - i;
				start = i;
				end = lower - arr;
			}
		}
		cout << maxx <<  ' ' << arr[start] << ' ' << arr[end-1] <<endl;
	}
	return 0;
}