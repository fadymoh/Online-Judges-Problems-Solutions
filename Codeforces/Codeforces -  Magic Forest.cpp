#include <iostream>
using namespace std;

int main()
{

	long long n, sum = 0;
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			int xor = i ^ j;
			if (xor <= n && (i+j) > xor && (i + xor) > j && (j + xor) > i)
			{
				++sum;
			}
		}
	}
	cout << sum / 3 << endl;
	return 0;
}