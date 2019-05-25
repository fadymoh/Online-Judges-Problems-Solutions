#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	int n, x, curr;
	scanf("%d %d", &n, &x);
	unordered_set<int> mySet;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &curr);
		mySet.insert(curr);
	}
	if (mySet.size() != n) puts("0");
	else
	{
		unordered_set<int> andSet;
		bool oneOp = false, twoOp = false;
		for (auto &it : mySet)
		{
			int andRes = it & x; // will give me a number less than or equal to x
			auto its = andSet.find(andRes);
			if (its != andSet.end())
			{
				if (mySet.find(andRes) != mySet.end())
					oneOp = true;
				else
					twoOp = true;
			}
			andSet.insert(andRes);
		}
		if (oneOp) puts("1");
		else if (twoOp) puts("2");
		else puts("-1");
	}
	return 0;
}