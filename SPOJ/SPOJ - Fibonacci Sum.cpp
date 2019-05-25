#include <iostream>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;

const int mod = 1000000007;

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
	int n, t, mm;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &mm);
		mul m(3);
		vector< vector<int> > mat(3, vector<int>(3));

		mat[0][0] = mat[0][2] = mat[1][2] = mat[2][0] = 0;
		mat[0][1] = mat[1][0] = mat[1][1] = mat[2][1] = mat[2][2] = 1;
		int first;
		if (mm <= 0) first = 0;
		else if (mm == 1) first = 1;
		else
		{
			mat = power(mat, mm, m);
			first = mat[2][1];
		}
		mat[0][0] = mat[0][2] = mat[1][2] = mat[2][0] = 0;
		mat[0][1] = mat[1][0] = mat[1][1] = mat[2][1] = mat[2][2] = 1;
		int second;
		if (n - 1 <= 0) second = 0;
		else if (n - 1 == 1) second = 1;
		else
		{
			mat = power(mat, n - 1, m);
			second = mat[2][1];
		}

		printf("%d\n", (first - second + mod) % mod);
	}
	return 0;
}