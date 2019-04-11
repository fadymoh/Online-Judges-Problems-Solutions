#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
int arr[100001];
int count[100001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	int i = 0, j = 0;
	int m = 1000000;
	std::unordered_set <int> distinctElements;
	
	while (j < n && distinctElements.size() != k) // that elements is not inside
	{
		++count[arr[j]];
		if (distinctElements.find(arr[j]) == distinctElements.end()) distinctElements.insert(arr[j]);
		++j;
	}
	--j;
	if (distinctElements.size() != k)
		printf("%d %d", -1, -1);
	else
	{
		while (i < n - 1)
		{
			if (count[arr[i]] == 1) break;
			else --count[arr[i]];
			++i;
		}
		printf("%d %d", i+1, j+1);
	}
		return 0;
}