#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e6;
char patt[N], str[N];

int f[N];
int getLen(int l, char c) {
	while (l && patt[l] != c)
		l = f[l-1];
	if (patt[l] == c)
		l++;
	return l;
}

void computeFailure()
{
	f[0] = 0;
	for (int i = 1; patt[i]; ++i)
		f[i] = getLen(f[i - 1], patt[i]);
}
int findCut()
{
	int l = 0;
	for (int i = 0; str[i]; ++i)
		l = getLen(l, str[i]);
	return l;
}
int main()
{
	while (scanf("%s", str) == 1) {
		int mlength = strlen(str);
		strcpy(patt, str);
		reverse(patt, patt+mlength);
		memset(f, 0, sizeof f);
		computeFailure();
		int cut = findCut();
		printf("%s", str);
		for (int i = cut; i <= mlength - 1; ++i)
			printf("%c", patt[i]);
		puts("");
		
	}
	return 0;
}