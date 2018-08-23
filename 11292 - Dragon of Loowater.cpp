#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m, n != 0)
	{
		vector<int> mDragon(n), mKnights(m);
		bool fought[20001] = { 0 };
		for (int i = 0; i < n; ++i)
			cin >> mDragon[i];
		for (int i = 0; i < m; ++i)
			cin >> mKnights[i];
		if (n > m) cout << "Loowater is doomed!\n";
		else
		{
			sort(mDragon.begin(), mDragon.end());
			sort(mKnights.begin(), mKnights.end());
			int sum = 0;
			bool game_over = false;
			int j = 0;
			for (int i = 0; i < n; ++i)
			{
				bool killed = false;
				for (; j < m; ++j)
				{
					
						if (mKnights[j] >= mDragon[i])
						{
							killed = true;
							sum += mKnights[j];
							fought[j++] = true;
							break;
						}
				
				}
				if (!killed)
				{
					game_over = true;
					break;
				}
			}
			if (!game_over) cout << sum << endl;
			else cout << "Loowater is doomed!" << endl;
		}
	}
	system("pause");
	return 0;
}