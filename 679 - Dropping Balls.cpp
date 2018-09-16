#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
bool tree[1048575];
int output[22][524288];
int simulate(int node, int depth, int max)
{
	if (depth == max) return node;
	if (!tree[node])
	{
		tree[node] = true;
		return simulate(node * 2 + 1, depth + 1, max);
	}
	tree[node] = false;
	return simulate(node * 2 + 2, depth + 1, max);
}
int main()
{
	for (int i = 2; i < 21; ++i)
	{
		memset(tree, false, sizeof tree);
		for (int j = 1; j < 524289; ++j)
			output[i][j] = simulate(0, 1, i) + 1;
	}
	int tc, d, i;
	cin >> tc;
	while (tc--)
	{
		cin >> d >> i;
		cout << output[d][i] << endl;
	}
	cin >> tc;
	return 0;
}