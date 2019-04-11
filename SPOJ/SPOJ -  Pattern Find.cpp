#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

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
void computeFailure() {
	f[0] = 0;
	for (int i = 1; patt[i]; i++)
		f[i] = getLen(f[i - 1], patt[i]);
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
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%s %s", str, patt);
		computeFailure();
		auto res = findLocs();
		if (res.empty()) puts("Not Found");
		else {
			int sz = res.size();
			printf("%d\n", sz);
			for (int i = 0; i < sz; ++i)
			{
				printf("%d%c", res[i] + 1, "\n "[!!(i != sz - 1)]);
			}
		}
		puts("");

	}
	return 0;
}