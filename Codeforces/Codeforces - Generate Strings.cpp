#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool getBit(int mask, int i)
{
	return mask & (1 << i);
}
unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	return ((b) ? gcd(b, a%b) : a);
}
unsigned long long int LCM(unsigned long long int x, unsigned long long int y)
{
	return x * y / gcd(x, y);
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		unsigned long long int n, x;
		cin >> n >> x;
		int a[11];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			a[i] *= 2;
		}
		unsigned long long int res = 0;
		for (int mask = 1; mask < (1 << n); ++mask)
		{
			unsigned long long int lcm = 1;
			unsigned long long int cnt = 1;
			for (int i = 0; i < n; ++i)
			{
				if (getBit(mask, i) == true)
				{
					lcm = LCM(lcm, a[i]);
					++cnt;
				}
			}
			if (cnt % 2 == 0)
				res += x / lcm;
			else
				res -= x / lcm;
		}
		cout << res<< endl;
	}
	return 0;
}
