#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, f;
int piRadius[10001];
#define EPS 1e-6
const double pi = 3.14159265359;
bool valid(double max)
{
	int pieces = 0;
	for (int i = 0; i < n; ++i)
		pieces += (piRadius[i] * piRadius[i] * pi / max);
	return pieces >= (f + 1);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &f);
		int r;
		for (int i = 0; i < n; ++i)
			scanf("%d", &piRadius[i]);
		double start = 0, sz = 1e9;
		for (sz /= 2; sz > EPS; sz /= 2)
			if (valid(start + sz))
				start += sz;
		printf("%.4f\n", start);
	}
	return 0;
}