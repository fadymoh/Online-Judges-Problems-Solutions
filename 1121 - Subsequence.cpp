#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
long long arr[100000];
long long solve(void)
{
	bool flag = false;
	long long i = 0, j = 0;
	long long ans = 100000000, cur = 0;
	while (j < n || cur >= s)
	{
		while (j < n && cur < s) cur += arr[j++];
		if (cur >= s)
		{
			flag = true;
			ans = min(ans, j - i);
			cur -= arr[i++];
		}
	}

	return (flag) ? ans : 0;
}
int main()
{
	while (cin >> n >> s, !cin.eof())
	{
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << solve() << endl;
	}
	return 0;
}