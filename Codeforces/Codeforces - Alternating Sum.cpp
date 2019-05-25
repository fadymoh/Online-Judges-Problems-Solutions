#include <iostream>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;

const int mod = 1000000007;

struct mul
{
	int sz;
	mul(int s) : sz(s) {}

	vector <vector<int>> operator()(const vector<vector<int>> &a, const vector<vector<int>> &b) consst
	{
		vector<vector<int>> v(a.size(), vector<int>(b[0].size()));
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < b[0].size(); ++j)
			{
				for (int k = 0; k < a[0].size(); ++k)
				{
					v[i][j] += (1LL * a[i][k] * b[k][j]) % mod;
					v[i][j] %= mod;
				}
			}
		}
		return v;
	}
};

vector<vector<int>> identity_element(const mul& m)
{
	vector<vector<int>> v(m.sz, vector<int>(m.sz));
	for (int i = 0; i < m.sz; ++i)
		v[i][i] = 1;
	return v;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int k, i;
		cin >> k >> i;
		mul m(k);
		vector<vector<int>> b(k, vector<int>(1));
		vector<vector<int>> mat(k, vector<int>(k));
		for (int i = 0; i < k; ++i)
			cin >> b[i][0];

		// define your matrix
		for (int i = 0; i + 1< k; ++i)
			mat[i][i + 1] = 1;
		int flag = 0;
		for (int i = k - 1; i >= 0; --i)
		{
			mat[k][i] = (flag == 0) ? 2 : 1;
			flag ^= 1;
		}
		// end
		mat = power(mat, i, m);
		b = m(mat, b);
		cout << b[k - 1][0] << endl;
	}
	return 0;
}