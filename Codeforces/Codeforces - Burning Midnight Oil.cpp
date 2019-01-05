#include <iostream>
using namespace std;
int n, k;
bool valid(long long v)
{
	long long sum = v;
	int i = 1;
	long long kPow = k;
	while (v / kPow)
	{
		sum += v / kPow;
		kPow *= k;
	}
	return sum >= n;
}
int main()
{
	cin >> n >> k;
	int left = k, right = n;
	if (n <= k) {
		cout << n << endl;
		return 0;
	}
	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		if (valid(mid)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left << endl;
	return 0;
}