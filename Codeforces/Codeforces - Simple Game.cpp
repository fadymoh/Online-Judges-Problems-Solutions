#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main()
{
	unsigned long n, m;
	scanf("%lu %lu", &n, &m);

	if (n == 1)
		puts("1");
	else
	{
		if (n - m <= m - 1)
			printf("%lu\n", m - 1);
		else
			printf("%lu\n", m + 1);
	}
	return 0;
}