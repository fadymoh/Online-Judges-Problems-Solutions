#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n)
	{
		vector<int> mVector(n + 1);
		for (int i = 0; i < n; ++i)
			cin >> mVector[i];
		sort(mVector.begin(), mVector.end() - 1);
		int prev = -1, occur = 0, maxx = -1;
		for (int i = 0; i <= n; ++i)
		{
			if (mVector[i] == prev) ++occur;
			else
			{
				prev = mVector[i];
				maxx = max(maxx, occur);
				occur = 1;
			}
		}
		vector<vector<int>> mOutput(maxx);
		cout << maxx << endl;
		for (int i = 0; i < n; ++i)
			mOutput[i % maxx].push_back(mVector[i]);
		for (int i = 0; i < mOutput.size(); ++i)
		{
			for (int j = 0; j < mOutput[i].size(); ++j)
			{
				cout << mOutput[i][j] << ((j == mOutput[i].size() - 1) ? '\n' : ' ');
			}
		}
		cin >> n;
		if (n)
			cout << endl;
		else
			break;
	}

	system("pause");
	return 0;
}