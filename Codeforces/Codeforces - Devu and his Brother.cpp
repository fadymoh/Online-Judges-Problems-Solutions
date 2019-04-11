#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;
ll firstArr[100001];
ll secondArr[100001];
ll n, m;
ll f(ll X) 
{
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		if (firstArr[i] < X) sum += abs(firstArr[i] - X);
	for (int i = 0; i < m; ++i)
		if (secondArr[i] > X) sum += abs(secondArr[i] - X);
	return sum;
}
ll ternary(ll s, ll e) 
{
	while (s < e)
	{
		ll g = s + (e - s) / 3;
		ll h = s + 2 * (e - s) / 3;
		if (f(g) > f(h)) // change < to > if inc then dec
			s = g + (s == g);
		else
			e = h - (e == h);
	}
	return f(s);
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &firstArr[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &secondArr[i]);
	cout << ternary(0, 1e9 + 1) << endl;

	return 0;
}