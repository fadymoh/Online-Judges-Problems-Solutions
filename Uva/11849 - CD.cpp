#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, n != 0 && m != 0)
	{
		set <int> mSet;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			mSet.insert(temp);
		}
		int counter = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			auto ret = mSet.insert(temp);
			if (ret.second == false)
				counter++;
		}
		cout << counter << endl;
	}

	system("pause");
	return 0;
}