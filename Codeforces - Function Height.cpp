#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
	unsigned long long int n;
	unsigned long long int k;
	cin >> n >> k;
	unsigned long long int ans = k / n;
	if (k % n > 0) ++ans;
	cout << ans << endl;
	return 0;
}