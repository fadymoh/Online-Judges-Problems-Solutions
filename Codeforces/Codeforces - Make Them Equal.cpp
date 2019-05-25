#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int mn = 1e9, mx = -1e9;
	int n, curr;
	set<int> orderedSet;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		orderedSet.insert(curr);
	}
	int sz = orderedSet.size();
	if (sz > 3) puts("-1");
	else
	{
		/*
			1) if the size is 1, then i dont need to do any changes
			2) if the size is 2, then print the absolute difference between the two values
			3) if the size is 3, then i need to check the difference between the outliers, if they are equal to the middle value
		*/
		int first, second, third;
		auto it = orderedSet.begin();
		if (sz == 1) puts("0");
		else if (sz == 2)
		{
			first = *it;
			++it;
			second = *it;
			int diff = abs(first - second) / 2;
			if (diff + first == second-diff)
				printf("%d\n", diff);
			else
				printf("%d\n", abs(first - second));
		}
		else
		{
			first = *it;
			++it;
			second = *it;
			++it;
			third = *it;
			int diff = abs(first - third) / 2;
			if (diff + first == second && third - diff == second)
				printf("%d", diff);
			else
				puts("-1");
		}
	}
	return 0;
}