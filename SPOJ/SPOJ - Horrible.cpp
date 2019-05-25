#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 17;
long long seg[N << 2], lazy[N << 2];

int n;
long long query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1) {
	if (qs > ne || qe < ns)
		return 0;

	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1) + 1, rt = lf + 1;

	//seg[id] += lazy[id] * (ne - ns + 1);
	seg[lf] += (mid - ns + 1) * lazy[id];
	seg[rt] += (ne - mid) * lazy[id];
	lazy[lf] += lazy[id];
	lazy[rt] += lazy[id];
	lazy[id] = 0;


	if (qs <= ns && ne <= qe)
		return seg[id];


	long long ans1 = query(qs, qe, lf, ns, mid);
	long long ans2 = query(qs, qe, rt, mid + 1, ne);
	//seg[id] = seg[lf] + seg[rt];

	return ans1 + ans2;
}

void update(int qs, int qe, int val, int id = 0, int ns = 0, int ne = n - 1) {
	if (qs > ne || qe < ns)
		return;


	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1) + 1, rt = lf + 1;

	//seg[id] += lazy[id] * (ne - ns + 1);
	seg[lf] += (mid - ns + 1) * lazy[id];
	seg[rt] += (ne - mid) * lazy[id];
	lazy[lf] += lazy[id];
	lazy[rt] += lazy[id];
	lazy[id] = 0;


	if (qs <= ns && ne <= qe) {
		lazy[id] += val;
		seg[id] += 1ll * val * (ne - ns + 1);
		return;
		// return seg[id] = val, void; NOT important, IGNORE IT
	}

	update(qs, qe, val, lf, ns, mid);
	update(qs, qe, val, rt, mid + 1, ne);
	seg[id] = seg[lf] + seg[rt];
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);

		int t;
		scanf("%d", &t);
		while (t--) {
			int q, qs, qe, qv;
			scanf("%d %d %d", &q, &qs, &qe);
			if (q) {
				printf("%lld\n", query(--qs, --qe));
			}
			else {
				scanf("%d", &qv);
				update(--qs, --qe, qv);
			}
		}
	}
	return 0;
}