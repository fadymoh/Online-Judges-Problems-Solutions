#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main()
{

	int n;
	scanf("%d", &n);
	long long out = 0;
	int prevIDX = -1;
	int curr;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		if (curr)
		{
			if (prevIDX == -1) out = 1;
			else out *= i - prevIDX;
			prevIDX = i;
		}
	}
	printf("%lld\n", out);

	return 0;
}