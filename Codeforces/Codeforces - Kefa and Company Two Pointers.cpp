#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, d, money, factor;
	cin >> n >> d;
	vector<pair<int, int>> mVector(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> money >> factor;
		mVector[i].first = money;
		mVector[i].second = factor;
	}
	sort(mVector.begin(), mVector.end());
	long long mx = 0;
	long long sum = 0;
	int e = 0;
	for (int i = 0; i < n; ++i)
	{
		while (e < n && mVector[e].first - mVector[i].first < d)
			sum += mVector[e++].second;
		mx = max(mx, sum);
		sum -= mVector[i].second;
	}
	cout << mx << endl;
	return 0;
}