#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		int left = n - i;
		if ((left % i) == 0) ++ans;
	}
	cout << ans << endl;
	return 0;
}