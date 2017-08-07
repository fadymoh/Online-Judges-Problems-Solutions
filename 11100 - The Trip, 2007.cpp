#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cmath>
#include <list>
#include <iomanip>
using namespace std;
vector <int> input;
vector <vector <int> > solution;
bool used[10000] = { 0 };
int n, idx;
bool check_all()
{
	for (int i = 0; i < n; i++)
	{
		if (used[i] == false) return false;
	}
	return true;
}
void recurse(int k, int index, int ret )
{
	if (k + ret >= n) return; 
	int j = k + ret;
	solution[index].push_back(input[j]);
	used[j] = true;
	recurse( j, index, ret);
}
int main()
{
	bool enter = false;
	while (cin >> n, n != 0){
		solution.clear();
		input.clear();
		solution.resize(n);
		input.resize(n);
		for (int i = 0; i < n; i++)
			cin >> input[i];
		sort(input.begin(), input.end());
		int ret = 1, cnt = 1;
		for (int i = 1; i < n; ++i) {
			if (input[i] == input[i - 1]) cnt++;
			else ret = max(ret, cnt), cnt = 1;
		}
		ret = max(ret, cnt);
		if (enter)puts("");
		enter = true;
		printf("%d\n", ret);
		for (int i = 0; i < ret; i++)
			recurse(i - ret, i, ret);
		
		for (int i = 0; i < ret; i++){
			int x = solution[i].size();
			for (int j = 0; j < x; j++){
				cout << solution[i][j];
				if (j != x - 1) cout << " ";
			}
			cout << endl;
		}

	}
	system("pause");
	return 0;
}
