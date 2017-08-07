#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		vector <int> dragon(n);
		vector <int> knights(m);
		int used[20001] = { 0 };
		for (int i = 0; i < n; i++)
			cin >> dragon[i];
		for (int i = 0; i < m; i++)
			cin >> knights[i];
		sort(dragon.begin(), dragon.end());
		sort(knights.begin(), knights.end());
		int ans = 0;
			bool doomed = false;
			for (int i = 0, j = 0; i < n && !doomed; i++){
				while (j < m && knights[j] < dragon[i]) ++j;

				if (j == m) doomed = true;
				else ans += knights[j++];

			}
			if (doomed)cout << "Loowater is doomed!" << endl;
			else
			cout << ans << endl;
		
	}
	system("pause");
	return 0;
}
