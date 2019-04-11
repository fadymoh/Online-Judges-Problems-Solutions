#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
int main()
{
	cin >> n;
	long long counter = 1, temp, prev, maxx, output = 1;
	vector<long long> mVector(n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> mVector[i];
	}
	for (long long i = 1; i < n; ++i)
	{
		if (mVector[i] > mVector[i - 1] * 2) counter = 0;
		++counter;
		output = max(output, counter);
	}

	cout << output << endl;
	system("pause");
	return 0;
}