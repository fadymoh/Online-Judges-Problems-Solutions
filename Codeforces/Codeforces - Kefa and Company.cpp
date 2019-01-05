#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, d, money, factor;
	cin >> n >> d;
	vector<pair<int, int>> mVector(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> money >> factor;
		mVector[i] = make_pair(money, factor);			
	}
	sort(mVector.begin(), mVector.end());
	long long arr[100005];
	for (int i = 0; i < n; ++i)
		arr[i + 1] = arr[i] + mVector[i].second;
	long long mx = 0;
	for (int i = 0; i < n; ++i)
	{
		pair <int, int> p = make_pair(mVector[i].first + d -1, (int)2e9);
		int en = upper_bound(mVector.begin(), mVector.end(), p) - mVector.begin();
		mx = max(mx, arr[en] - arr[i]);
	}
	cout << mx << endl;

	return 0;
}
