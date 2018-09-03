#include <iostream>
using namespace std;

int main()
{
	int n, m, temp, sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
		cout << sum / m << endl;
		sum %= m;
	}
	return 0;
}
