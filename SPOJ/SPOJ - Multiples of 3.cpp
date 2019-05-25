#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 1 << 17;
struct point
{
	int x = 1, y, z;
};
point seg[N << 2];
int lazy[N << 2];

int n;
void propagate(int id, int left, int right)
{
	if (lazy[id]) // if there is lazy
	{
		lazy[id] %= 3;
		if (left != right)
		{
			int lf = (id << 1), rt = lf + 1;
			lazy[lf] = (lazy[lf] + lazy[id]) % 3;
			lazy[rt] = (lazy[rt] + lazy[id]) % 3;
		}
		if (lazy[id] == 1)
		{
			int temp = seg[id].z;
			seg[id].z = seg[id].y;
			seg[id].y = seg[id].x;
			seg[id].x = temp;
		}
		else if (lazy[id] == 2)
		{
			int temp = seg[id].z;
			seg[id].z = seg[id].x;
			seg[id].x = seg[id].y;
			seg[id].y = temp;
		}
		lazy[id] = 0;
	}
}
int query(int qs, int qe, int id = 1, int ns = 1, int ne = n) {
	propagate(id, ns, ne);
	if (qs > ne || qe < ns)
		return 0;

	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1), rt = lf + 1;

	if (qs <= ns && ne <= qe)
		return seg[id].x;


	int ans1 = query(qs, qe, lf, ns, mid);
	int ans2 = query(qs, qe, rt, mid + 1, ne);
	//seg[id] = seg[lf] + seg[rt];

	return ans1 + ans2;
}



point update(int qs, int qe, int id = 1, int ns = 1, int ne = n) {

	propagate(id, ns, ne);
	if (qs > ne || qe < ns)
		return seg[id];

	int mid = ns + (ne - ns) / 2;
	int lf = (id << 1), rt = lf + 1;

	// if i encapsulate the whole range
	if (qs <= ns && ne <= qe) {
		lazy[id] = 1;
		propagate(id, ns, ne);
		return seg[id];
		// return seg[id] = val, void; NOT important, IGNORE IT
	}

	point p1 = update(qs, qe, lf, ns, mid);
	point p2 = update(qs, qe, rt, mid + 1, ne);
	seg[id].x = p1.x + p2.x;
	seg[id].y = p1.y + p2.y;
	seg[id].z = p1.z + p2.z;
	return seg[id];
}
void build(int id, int qs, int qe)
{
	// so basically here i am creating the tree
	if (qs == qe)
	{
		seg[id].x = 1;
		return;
	}
	int mid = qs + (qe - qs) / 2;
	int lf = (id << 1), rt = lf + 1;
	build(lf, qs, mid);
	build(rt, mid + 1, qe);
	seg[id].x = seg[lf].x + seg[rt].x;
}
int main() {
	int Q;
	scanf("%d %d", &n, &Q);
	build(1, 1, n);
	while (Q--) {
		int op, A, B;
		scanf("%d %d %d", &op, &A, &B);
		++A, ++B;
		if (op == 0)
			update(A, B);
		else
			printf("%d\n", query(A, B));
	}
	return 0;
}