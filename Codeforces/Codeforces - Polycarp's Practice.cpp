#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	priority_queue<pair<int, int>> myHeap;

	int n, k;
	scanf("%d %d", &n, &k);
	int curr;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &curr);
		myHeap.push({ curr, i });
	}
	vector<int> myIDX(k);
	long long profit = 0;
	int temp = k;
	while (temp--)
	{
		auto it = myHeap.top();
		profit += it.first;
		myIDX[temp] = it.second;
		myHeap.pop();
	}
	printf("%lld\n", profit);
	sort(myIDX.begin(), myIDX.end());
	int prev = 0;
	for (int i = 0; i < k - 1; ++i) {
		printf("%d ", myIDX[i] - prev);
		prev = myIDX[i];
	}
	printf("%d\n", n - prev);
	return 0;
}