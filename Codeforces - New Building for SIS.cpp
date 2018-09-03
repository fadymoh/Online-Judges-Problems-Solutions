#include <iostream>
using namespace std;

int main()
{
	int n, h, a, b, k, ta, fa, tb, fb;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> ta >> fa >> tb >> fb;
		int ans = 0;
		if (ta != tb)
		{
			if (fa > b) ans += (fa - b), fa = b;
			if (fa < a) ans += (a - fa), fa = a;
			ans += abs(tb - ta);
			ans += abs(fb - fa);
			cout << ans << endl;
		}
		else
		{
			cout << abs(fa - fb) << endl;
		}
	}
	return 0;
}