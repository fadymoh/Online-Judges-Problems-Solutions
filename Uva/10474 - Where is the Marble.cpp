#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, q, case_counter = 0;
	while (cin >> n >> q, n != 0 && q != 0)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		int temp;
		cout << "CASE# " << ++case_counter << ":\n";
		for (int i = 0; i < q; ++i)
		{
			cin >> temp;
			auto it = lower_bound(arr.begin(), arr.end(), temp);

			if (it == arr.end() || *it != temp)
				cout << temp << " not found";
			else
				cout << temp << " found at " << it - arr.begin() + 1;
			cout << endl;
 		}
	}
	return 0;
}