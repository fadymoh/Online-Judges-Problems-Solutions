#include <iostream>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;

const int mod = 98765431;

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
				for (int k = 0; k<a[0].size(); k++)
					v[i][j] = (v[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
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
	int n, t;
	scanf("%d %d", &n, &t);

	mul m(n);
	vector< vector<int> > b(n, vector<int>(1));
	vector< vector<int> > mat(n, vector<int>(n, 1));

	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i][0]);

	for (int i = 0; i < n; i++)
		mat[i][i] = 0;

	mat = power(mat, t, m);
	b = m(mat, b);

	for (int i = 0; i < n; ++i)
		printf("%d\n", b[i][0]);

	return 0;
}