#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[20];

bool getbit(int mask, int ind)
{
	return (mask >> ind) & 1;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int m = (1 << n);

	for (int i = 0; i < m; ++i)
	{
		int deg = 0;
		for (int j = 0; j < n; ++j)
		{
			if (getbit(i, j))
				deg += arr[i];
			else
				deg -= arr[i];
		}
		if (deg % 360 == 0)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}