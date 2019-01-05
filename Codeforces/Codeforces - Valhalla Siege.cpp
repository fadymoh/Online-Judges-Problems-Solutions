#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	long long temp;
	vector<long long> cumm(n);
	cin >> cumm[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> temp;
		cumm[i] = cumm[i - 1] + temp;
	}
	long long ind = 0;
	long long query;
	for (int i = 0; i < q; ++i)
	{
		cin >> query;
		int bound = upper_bound(cumm.begin() + ind, cumm.end(), query) - cumm.begin();
		if (bound == n) // didnt find any value greater than
		{
			ind = 0;
		}
		else
		{
			ind += bound;
		}
		cout << n - ind << endl;
	}
	return 0;
}