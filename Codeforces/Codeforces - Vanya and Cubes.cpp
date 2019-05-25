#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int n, levels = 1, sum = 0;
	scanf("%d", &n);
	while (sum + int(levels*(levels + 1) / 2) <= n)
	{
		sum += (levels*(levels + 1) / 2); 
		++levels;
	}
	printf("%d\n", levels - 1);

	return 0;
}