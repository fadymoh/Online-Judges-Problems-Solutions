#include <iostream>
#include <algorithm>
using namespace std;
long long n;
bool valid(long long k)
{
	long long vasya = 0;
	long long box = n;
	while (box > 0)
	{
		if (k >= box)
		{
			vasya += box;
			box = 0;
		}
		else
		{
			vasya += k;
			box -= k;
		}	
		box =box - box / 10;
	}
	return vasya >= n / 2 + n % 2;
}
int main()
{

	cin >> n;
	long long xl = 1, xu = n, mid, ans = -1;
	while (xu >= xl)
	{
		mid = xl + (xu - xl + 1) / 2;
		if (valid(mid)) //doable, so decrease the next value of mid
		{
			if (ans == -1) ans = mid;
			else ans = min(ans, mid);
			xu = mid - 1;
		}
		else
			xl = mid + 1; // not doable so increase the next value of mid
	
	}
	cout << ans << endl;
	return 0;
}