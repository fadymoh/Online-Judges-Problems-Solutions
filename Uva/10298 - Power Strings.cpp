#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int N = 1e6;
char patt[N], str[N];

int f[N];
int getLen(int l, char c) {
	while (l && str[l] != c)
		l = f[l];
	if (str[l] == c)
		l++;
	return l;
}
void computeFailure() {
	f[0] = 0;
	for (int i = 1; patt[i]; i++)
		f[i] = getLen(f[i - 1], patt[i]);
}
int main() {
	while (scanf("%s", str) == 1 && strcmp(str, ".")) {
		int length = strlen(str);
		memset(f, 0, sizeof f);
		for (int i = 2; i <= length; ++i)
		{
			f[i] = getLen(f[i - 1], str[i-1]);
		}
		int period = 0;
		for (int i = 1; i <= length; i++)
			if (i - f[i] > period)
				period = i - f[i];

		if (length % period != 0)
			period = length;
		printf("%d\n", length / period);
	}
}