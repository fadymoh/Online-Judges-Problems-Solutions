#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1 << 18;
int seg[N << 1];

int n;
int query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1) {
	if (qs > ne || qe < ns)	   // return an invalid value 
		return 0;
	// qs | ns | ne | qe, i need to encapsulate the whole range to return its value
	if (qs <= ns && ne <= qe)
		return seg[id];

	// handles negative by ceiling in negative and flooring in positive plus overflow
	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1) + 1, rt = lf + 1;

	int ans1 = query(qs, qe, lf, ns, mid);
	int ans2 = query(qs, qe, rt, mid + 1, ne);

	// the operation we need to perform
	return ans1 + ans2;
}

void update(int pos, int val, int id = 0, int ns = 0, int ne = n - 1) {
	if (pos > ne || pos < ns)
		return;
	if (ns == ne) {
		seg[id] = val;
		return;
		// return seg[id] = val, void; NOT important, IGNORE IT
	}

	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1) + 1, rt = lf + 1;
	update(pos, val, lf, ns, mid);
	update(pos, val, rt, mid + 1, ne);
	// go to the depth of the tree and update while going backwards
	seg[id] = seg[lf] + seg[rt];
}
int main() {
	
	int x, y, cases = 0;
	char op[10], cmd[50];
	while (scanf("%d", &n), n != 0)
	{
		int u;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &u);
			update(i, u);
		}

		while (getchar() != '\n');
		if (cases) puts("");
		printf("Case %d:\n", ++cases);

		while (gets_s(cmd))
		{
			if (cmd[0] == 'E') break;
			sscanf(cmd, "%s %d %d", op, &x, &y);
			if (op[0] == 'M')
			{
				//query
				printf("%d\n", query(--x, --y));
			}
			else
			{
				//update
				update(--x, y);
			}
		}
	}
	return 0;
}