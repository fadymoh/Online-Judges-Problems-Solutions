#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m;

bool opr(const int &first,const int &second)
{
	if (first % m != second % m)
		return first % m < second % m;
	if (first & 1) // i is odd
	{
		if (second & 1)
			return first > second;
		return true;
	}
	if (second & 1)
	{
		return false;
	}
	return first < second;
}
int main()
{
	int n;
	while (cin >> n >> m, n != 0 && m != 0)
	{
		cout << n << ' ' << m << '\n';
		vector <int> mVector(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> mVector[i];
		}
		sort(mVector.begin(), mVector.end(), opr);
		for (int i = 0; i < n; ++i)
		{
			cout << mVector[i] << endl;;
		}
	}
	cout << "0 0\n";
	system("pause");
	return 0;
}