#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int b[N];
vector<vector<int>> t;
int main()
{
	int n;
	scanf("%d", &n);
	t.resize(n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", b + i);

	for (int i = 0; i <= 3; ++i)
	{
		for (int j = 0; j <= 3; ++j)
		{
			if (((i | j) == a[0]) && ((i & j) == b[0]))
			{
				t[0].push_back(i);
				t[1].push_back(j);
			}
		}
	}
	for (int i = 1; i < n - 1; ++i)
	{
		for (auto element : t[i])
		{
			for (int j = 0; j <= 3; ++j)
			{
				if (((element | j) == a[i]) && ((element & j) == b[i]))
				{
					t[i+1].push_back(j);
				}
			}
		}
	}
	if (t[n - 1].size() == 0) puts("NO");
	else
	{
		puts("YES");
		int temp[N];
		temp[n - 1] = t[n - 1][0];
		for (int i = n - 2; i >= 0; --i)
		{
			for (auto element : t[i])
			{
				if (((element | temp[i+1]) == a[i]) && ((element & temp[i+1]) == b[i]))
				{
					temp[i] = element;
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", temp[i]);
	}

	return 0;
}
