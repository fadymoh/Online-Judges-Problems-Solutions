#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long mVector[1000005], cumm[1000005] = {0};
int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> mVector[i];
	sort(mVector, mVector + n);
	int left, right;
	for (int i = 0; i < q; ++i)
	{
		cin >> left >> right;
		++cumm[left-1];
		--cumm[right];
	}
	for (int i = 1; i < n; ++i)
		cumm[i] += cumm[i - 1];
	sort(cumm, cumm + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += mVector[i] * cumm[i];
	}
	cout << ans << endl;
	return 0;
}