#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const int N = 3*1e5 + 1;
int main()
{
	int sz;
	string in;
	char buffer[N];
	scanf("%d", &sz);
	scanf("%s", buffer);
	in = buffer;
	int i = 1;
	while (i < sz && in[i] >= in[i - 1]) ++i;

	if (i == sz)
		puts("NO");
	else
	{
		puts("YES");
		printf("%d %d\n", i, i + 1);
	}

	return 0;
}