#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, q;
	cin >> n >> q;
	long long x, y, ans;
	for (int i = 0; i < q; ++i)
	{
		cin >> x >> y;
		long long skip = (x-1)*n;
		ans = skip + y + 1;
		if ((x+y) % 2) 
			ans += (n * n);
		cout << ans / 2 << endl;
	}
	system("pause");
	return 0;
}