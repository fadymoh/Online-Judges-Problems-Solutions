#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstdio>

using namespace std;
struct comparatorr {
	bool operator() (const int& one, const int& two)
	{
		return one < two;
	}
};

bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		int operation, number;
		queue<int> mQueue;
		stack<int> mStack;
		priority_queue<int, std::vector<int>, comparatorr> minHeap;
		bool stack = true, queue = true, priority_queue = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> operation >> number;
			if (operation == 1) //inserting
			{
				mQueue.push(number);
				mStack.push(number);
				minHeap.push(number);
			}
			else
			{
				if (mQueue.empty() || mQueue.front() != number) queue = false;
				if (mStack.empty() || mStack.top() != number) stack = false;
				if (minHeap.empty() || minHeap.top() != number) priority_queue = false;
				if (!mQueue.empty()) mQueue.pop();
				if (!mStack.empty()) mStack.pop();
				if (!minHeap.empty()) minHeap.pop();
			}
		}
		if (stack + queue + priority_queue > 1)
			cout << "not sure";
		else if (stack)
			cout << "stack";
		else if (queue)
			cout << "queue";
		else if (priority_queue)
			cout << "priority queue";
		else cout << "impossible";
		cout << endl;
	}

	system("pause");
	return 0;
}