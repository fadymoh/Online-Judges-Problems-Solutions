#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mVector[101];
int lis[101];
int main()
{
	int temp, test_cases = 0;
	cin >> temp;
	while (temp != -1)
	{
		int n = 0;
		mVector[n++] = temp;
		while (cin >> temp, temp != -1) mVector[n++] = temp;

		for (int i = n - 1; i >= 0; --i)
		{
			int ans_lis = 0;
			int x = mVector[i];
			for (int j = i + 1; j < n; ++j)
			{
				if (mVector[j] <= x && ans_lis <= lis[j])
					ans_lis = lis[j];
			}
			lis[i] = ans_lis + 1;
		}
		int out_lis = 0;
		for (int i = 0; i < n; ++i)
			out_lis = max(out_lis, lis[i]);
		cout << "Test #" << ++test_cases << ":\n  maximum possible interceptions: " << out_lis << endl;
		cin >> temp;
		if (temp != -1) cout << endl;
	}
}