#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, arr[1001];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		int sum = 1, counter = (n > 1) ? 2 : 1;
		for (int i = 1; i < n - 1; ++i)
		{
			if (sum + arr[i] < arr[i + 1])
			{
				sum += arr[i];
				++counter;
			}
		}
		cout << counter << endl;
	}
	system("pause");
	return 0;
}