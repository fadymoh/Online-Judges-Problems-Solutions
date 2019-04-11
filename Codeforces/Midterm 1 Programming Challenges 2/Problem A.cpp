#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int cost, n, m;
const int N = 1e5 + 5;

int frm[N], to[N], cst[N];
long long dst[N];

bool bellmanford(int src)
{
	fill(dst, dst + N, INT_MAX);
	dst[src] = 0;
	bool edit = true;
	for (int i = 0; i <= n && edit; ++i)
	{
		edit = false;
		for (int j = 0; j < m; ++j)
		{
			if (dst[to[j]] > dst[frm[j]] + cst[j])
			{
				edit = true;
				dst[to[j]] = dst[frm[j]] + cst[j];
			}
		}
	}
	return edit;
}

int main()
{
	int tc;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//scanf("%d", &tc);
	cin >> tc;
	while (tc--)
	{
		//scanf("%d %d", &n, &m);
		cin >> n >> m;
		int u, v, c;
		for (int i = 0; i < m; ++i)
		{
			//scanf("%d %d %d", &u, &v, &c);
			cin >> u >> v >> c;
			--u; --v;
			frm[i] = u;
			to[i] = v;
			cst[i] = c;
		}
		if (bellmanford(0))
			cout << "-2000000000" << endl;
		else
		{
			long long sum = 1e9;
			for (int i = 1; i < n; ++i)
			{
				sum = min(dst[i], sum);
			}
			if (sum < 0)
				//printf("%lld\n", sum);
				cout << sum << endl;
			else
				//printf("%d\n", 0);
				cout << 0 << endl;
		}
	}

	return 0;
}
