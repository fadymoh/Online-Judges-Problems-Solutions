#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
char patt[N], str[N];
int f[N];

int getLen(int l, char c)
{
	while (l && patt[l] != c)
		l = f[l - 1];
	if (patt[l] == c)
		++l;
	return l;
}

void computeFailure()
{
	f[0] = 0;
	for (int i = 1; patt[i]; ++i)
		f[i] = getLen(f[i - 1], patt[i]);
}
vector<int> findLocs()
{
	vector<int> res;
	int l = 0;
	for (int i = 0; str[i]; ++i)
	{
		l = getLen(l, str[i]);
		if (!patt[l])
		{
			res.push_back(i - l + 1);
		}
	}
	return res;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%s", patt);
		scanf("%s", str);
		computeFailure();
		auto res = findLocs();
		long long out = 0;
		int pattLen = strlen(patt);
		int sz = res.size();
		for (int i = 0; i < sz; ++i)
		{
			if (i > 0 && i < sz-1) {
				int before = res[i - 1];
				int after = res[i + 1];
				int cur = res[i];
				if (abs(res[i] - before) < pattLen || abs(res[i] - after) < pattLen) ++out;
			}
			else if (i == sz-1) {
				int before = res[i - 1];
				int cur = res[i];
				if (abs(res[i] - before) < pattLen) ++out;
			}
			else
			{
				int after = res[i + 1];
				int cur = res[i];
				if (abs(res[i] - after) < pattLen) ++out;
			}
		}

		printf("%lld\n", out);
	}

	return 0;
}