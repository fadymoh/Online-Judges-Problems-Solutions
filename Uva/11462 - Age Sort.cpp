#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int counter[101];
int n;
void print(int x)
{
	for (int i = 0; i < 101; ++i)
	{
		int v = counter[i];
		while (v--) printf("%d%c", i, " \n"[!--x]);
	}
}
int main()
{
	while (cin >> n, n != 0)
	{
		memset(counter, 0, sizeof counter);
		int temp = n;
		for (int i; temp--;)
		{
			scanf_s("%d", &i);
			++counter[i];
		}
		print(n);
	}
	return 0;
}