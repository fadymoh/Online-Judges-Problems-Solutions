#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t,n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> mVector(n);
		for (int i = 0; i < n; ++i)
			cin >> mVector[i];
		int sum = 0;
		for (int i = 1; i < n; ++i)
			for (int j = i - 1; j >= 0; --j)
				if (mVector[j] <= mVector[i])
					++sum;
		cout << sum << endl;
	}
	system("pause");
	return 0;
}