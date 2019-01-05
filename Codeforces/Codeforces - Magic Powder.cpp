#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long n, k;
long long ingredients[100001];
long long grams[100001];
bool valid(long long cookies)
{
	long long needed = k;
	for (int i = 0; i < n; ++i)
		if (cookies*ingredients[i] > grams[i])
			if (cookies*ingredients[i] > grams[i] + needed)
				return false;
			else
				needed -= (cookies*ingredients[i] - grams[i]);
	return true;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> ingredients[i];
	for (int i = 0; i < n; ++i)
		cin >> grams[i];
	long long Xl = 0, Xu = 2e9+1;
	while (Xl <= Xu)
	{
		long long mid = Xl + (Xu - Xl + 1) / 2;
		if (valid(mid))
			Xl = mid + 1;
		else
			Xu = mid - 1;
	}
	cout << Xu << endl;
	return 0;
}