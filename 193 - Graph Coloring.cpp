#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
vector <vector <int> > graph;
int color[105]; //zero means white, 1 means black
int cases, n, k, a, b, maxx;
vector <int> solution;
bool neighbours(int idx)
{
	int size = graph[idx].size();
	for (int i = 0; i < size; i++){
		int val = graph[idx][i];
		if (color[val] == 1) return false;
	}
	return true; //non is black
}
int count()
{
	int counter = 0;
	for (int i = 0; i < 105; i++)
		if (color[i] == 1) counter++;
	return counter;
}
void backtrack(int x)
{
	if (x == n){
		int sum = count();
		if (sum >= maxx){
			maxx = sum;
			solution.clear();
			for (int i = 0; i < 105; i++)	
				if (color[i] == 1) solution.push_back(i);
		}
		return;
	}
		if (neighbours(x)){
			color[x] = 1;
			backtrack(x + 1);
		}
		color[x] = 0;
		backtrack(x + 1);
}
int main()
{
	int TC;
	cin >> TC;
	while (TC--)	{
		cin >> n >> k;
		graph.assign(n, vector<int>());
		color[105] = { 0 };
		maxx = 0;
		for (int i = 0; i < k; i++){
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		backtrack(0);
		printf("%d\n", maxx);
		for (int i = 0; i < solution.size(); i++) {
			printf("%d", solution[i] + 1);
			if (i < solution.size() - 1)
				printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

