#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> a;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> modulusBuckets(k);
	vector<int> mySolution(n);
	for (int i = 0; i < n; ++i)
	{
		modulusBuckets[i % k].push_back(a[i].first);
		mySolution[a[i].second] = i % k;
	}
	for (int i = 0; i < k; ++i)
	{
		int szBefore = modulusBuckets[i].size();
		auto it = unique(modulusBuckets[i].begin(), modulusBuckets[i].end());
		modulusBuckets[i].resize(distance(modulusBuckets[i].begin(), it)); // 10 20 30 20 10
		int szAfter = modulusBuckets[i].size();
		if (szBefore != szAfter)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 0; i < n; ++i)
		printf("%d ", mySolution[i] + 1);

	return 0;
}