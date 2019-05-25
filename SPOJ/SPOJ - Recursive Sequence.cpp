#include <iostream>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;

const int mod = 1000000000;

struct mul
{
	int sz;
	mul(int s) :sz(s) {}

	vector<vector<int> > operator()(const vector<vector<int> > &a,
		const vector<vector<int> > &b) const
	{
		vector< vector<int> > v(a.size(), vector<int>(b[0].size()));
		for (int i = 0; i<a.size(); i++)
			for (int j = 0; j<b[0].size(); j++)
				for (int k = 0; k<a[0].size(); k++) {
					v[i][j] += (1LL * a[i][k] * b[k][j]) % mod;
					v[i][j] %= mod;

				}
		return v;
	}
};

vector< vector<int> > identity_element(const mul& m)
{
	vector< vector<int> > v(m.sz, vector<int>(m.sz));
	for (int i = 0; i<m.sz; i++)
		v[i][i] = 1;
	return v;
}


int main()
{
	int t, k, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &k);
		mul m(k);
		vector< vector<int> > b(k, vector<int>(1));
		vector< vector<int> > mat(k, vector<int>(k));
		for (int i = 0; i < k; ++i)
			scanf("%d", &b[i][0]);

		for (int i = 0; i + 1 < k; ++i)
			mat[i][i + 1] = 1;
		for (int i = k - 1; i >= 0; --i)
			scanf("%d", &mat[k - 1][i]);

		scanf("%d", &n);

		mat = power(mat, n - 1, m);
		b = m(mat, b);
		printf("%d\n", b[0][0]);
	}
	return 0;
}