#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1e6 + 1;
int cnt[N];
int exist[N];
int main()
{
	int k, n, curr;
	scanf("%d %d", &k, &n);
	int idx = 1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		++cnt[curr];
		++exist[cnt[curr]];
		if (exist[idx] == k)
		{
			printf("1");
			++idx;
		}
		else printf("0");
	}

	

	return 0;
}