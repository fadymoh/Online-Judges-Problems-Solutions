#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int dup[N];
int main()
{
	int n, curr;
	scanf("%d", &n);

	bool over = false;
	vector<int> first, second;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		int &ref = dup[curr];
		++ref;
		if (ref == 1) first.push_back(curr);
		else if (ref == 2) second.push_back(curr);
		else if (ref == 3) over = true;
	}
	if (over) puts("NO");
	else
	{
		puts("YES");
		sort(first.begin(), first.end());
		sort(second.rbegin(), second.rend());
		printf("%d\n", first.size());
		for (int i = 0; i < first.size(); ++i)
			printf("%d ", first[i]);
		printf("\n%d\n", second.size());
		for (int i = 0; i < second.size(); ++i)
			printf("%d ", second[i]);
		puts("");
	}


	return 0;
}