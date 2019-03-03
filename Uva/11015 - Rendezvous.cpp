#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 24;
int Matrix[N][N];
int n, m;
void floydWarshal()
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
}

int main()
{
	int case_counter = 0;
	while (scanf("%d %d", &n, &m), n != 0 || m != 0)
	{
		memset(Matrix, 0x3f, sizeof Matrix);
		vector<string> names(n);
		for (int i = 0; i < n; ++i)
			cin >> names[i];
		int u, v, c;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &c); --u; --v;
			Matrix[u][v] = Matrix[v][u] = min(c, Matrix[u][v]);
		}

		floydWarshal();
		long long ans = 1e9, ind = -1;
		for (int i = 0; i < n; ++i)
		{
			long long sum = accumulate(Matrix[i], Matrix[i] + n, -Matrix[i][i]);
			if (sum < ans) ans = sum, ind = i;
		}
		cout << "Case #" << ++case_counter << " : " << names[ind] << '\n';
	}


	return 0;
}