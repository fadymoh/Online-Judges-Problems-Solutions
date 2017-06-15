#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int P, T, seen[102][102];
int parent[102], size;
int find_set(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x == y) return true;
	parent[x] = y;
	size--;
	return false;
}

bool same_opinion(int i, int j) {
	for (int k = 1; k <= T; k++)
	if (seen[i][k] != seen[j][k])
		return false;
	return true;
}
int main()
{
	
	set <int> myset;
	int  person, tree, cases;
	char terminate;
	char blank[200];
	gets(blank);
	cout << sizeof(seen) << endl;
	sscanf(blank, "%d", &cases);
	gets(blank);
	cout << sizeof(seen) << endl;
	while (cases--){

		gets(blank);
		memset(seen, 0, sizeof(seen));
		sscanf(blank, "%d%d", &P, &T);
		while (gets(blank) && sscanf(blank, "%d %d", &person, &tree) == 2)
			seen[person][tree] = 1;
			for (int i = 1; i <= P; i++)
				parent[i] = i;
			size = P;
			for (int i = 1; i < P ; i++)
				for (int j = i + 1; j <= P; j++){
					if (same_opinion(i, j))
						union_set(i, j);
				}
			cout << size << endl;
			if (cases) cout << endl;
	}
	cout << sizeof(seen) << endl;
	system("pause");
	return 0;
}