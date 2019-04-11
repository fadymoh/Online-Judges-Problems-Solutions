#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;
int tc, n;
const int N = 1e6;
char patt[N], str[N];
int f[N];
int getLen(int l, char c) {
	while (l && patt[l] != c)
		l = f[l - 1];
	if (patt[l] == c)
		l++;
	return l;
}
vector<int> findLocs() {
	vector<int> res;
	int l = 0;
	for (int i = 0; str[i]; i++) {
		l = getLen(l, str[i]);
		if (!patt[l]) {
			res.push_back(i - l + 1);
		}
	}
	return res;
}
void computeFailure() {
	f[0] = 0;
	for (int i = 1; patt[i]; i++)
		f[i] = getLen(f[i - 1], patt[i]);
}
int main()
{
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		vector<int> in(n);
		scanf("%d", &in[0]);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &in[i]);
			if (in[i] > in[i - 1]) str[i - 1] = 'G';
			else if (in[i] == in[i - 1]) str[i - 1] = 'E';
			else str[i - 1] = 'L';
		}
		scanf("%s", patt);
		computeFailure();
		auto res = findLocs();
		if (res.empty()) puts("NO");
		else puts("YES");
	}
	return 0;
}