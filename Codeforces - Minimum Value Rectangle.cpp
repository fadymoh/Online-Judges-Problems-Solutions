#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int tc, n;
	int arr[10001];
	multiset<int> pairs;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			arr[temp]++;
			if (arr[temp] > 1)
				pairs.insert(temp);
			arr[temp] %= 2;
		}
		auto it = pairs.begin();
		auto temp = it;
		long long point1 = (*it + *(++temp)) * (*it + *(++it));
		bool first;
		for (; it != pairs.end(); ++it)
		{
			
		}
		cout << ans[0] << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[1] << endl;

 	}
	system("pause");
	return 0;
}