#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long memo[301][301][301];
long long dp(int type, int value, int taken)
{
	long long &ret = memo[type][value][taken];
	
	if (value == 0 && taken == 0)
		return 1;
	if (value < 0 || type == 301 || taken <= 0)
		return 0;
	if (ret != -1) return ret;

	return ret = dp(type + 1, value, taken) + dp(type, value - type, taken -1);
		
}
int main()
{
	memset(memo, -1, sizeof(memo));
	char str[1000];
	while (gets_s(str)) {
		stringstream sin(str);
		int num[3], n = 0;
		while (sin >> num[n])
			n++;
		int p, q;
		long long ans = 0;
		if (n == 1)
		{
			for (int i = 1; i <= num[0]; ++i)
				ans += dp(1, num[0], i);
			if (num[0] == 0) ans = 1;
		}
		else if (n == 2)
		{
			for (int i = 1; i <= min(num[1],300); ++i)
				ans += dp(1, num[0], i);
			if (num[0] == 0) ans = 1;
		}
		else
		{
			for (int i = num[1]; i <= min(num[2],300); ++i)
				ans += dp(1, num[0], i);
			if (num[0] == 0 && num[1] == 0) ans = 1;
		}
		cout << ans << endl;
	}
	return 0;
}