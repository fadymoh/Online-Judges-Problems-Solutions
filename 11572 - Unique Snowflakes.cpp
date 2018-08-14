#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t, temp;
	cin >> t;
	
	while (t--)
	{
		cin >> n;
		vector<int> mVector(n);
		unordered_set <int> mSet;
		unordered_map <int, int> mMap;
		int maxx = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> mVector[i];
			if (mSet.find(mVector[i]) == mSet.end())
			{
				mSet.insert(mVector[i]);
			}
			else
			{
				maxx = max(maxx,(int) mSet.size());
				mSet.clear();
				for (int j = mMap[mVector[i]] + 1; j <= i; ++j)
				{
					mSet.insert(mVector[j]);
				}
			}
			mMap[mVector[i]] = i;
		}
		maxx = max(maxx, (int)mSet.size());
		cout << maxx << endl;
	}

	system("pause");
	return 0;
}