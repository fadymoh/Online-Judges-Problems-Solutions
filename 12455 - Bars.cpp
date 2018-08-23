#include <iostream>

using namespace std;

int main()
{
	int t, l, temp, n;
	cin >> t;
	while (t--)
	{
		cin >> l >> n;
		int arr[1001];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		bool flag = false;
		for (int i = 0; i < (1 << n); ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
			{
				if (i & (1 << j))
				{
					sum += arr[j];
				}
			}
			if (sum == l) {
				flag = true;
				break;
			}
		}
		if (!flag) cout << "NO\n";
		else cout << "YES\n";
		
	}

	system("pause");
	return 0;
}