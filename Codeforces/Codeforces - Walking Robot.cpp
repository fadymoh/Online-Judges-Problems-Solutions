#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, b, a, curr, i, maxA;
	scanf("%d %d %d", &n, &b, &a);
	maxA = a;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		if (b == 0 && a == 0) break;

		if (!a) // accum is zero, then i have to use the battery and recharge if possible
		{
			--b;
			if (curr) a = min(a + 1, maxA);
		}
		else if (!b)
			--a;
		else if (curr && a < maxA)
		{
			--b;
			a = min(a + 1, maxA);
		}
		else --a;
	}
	printf("%d\n", i);
	return 0;
}