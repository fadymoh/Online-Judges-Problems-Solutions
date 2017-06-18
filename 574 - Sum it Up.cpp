#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
int t, n, arr[20], sum, counter = 0;
bool used[20];
vector <vector<int> > solutions;
map <vector <int>, bool> mymap;
void backtrack(int x, vector<int> temp){
	if (sum == t) {
		if (!mymap[temp]){
			solutions.push_back(temp);
			mymap[temp] = true;
		}
		return;
	}
	if (x == n || sum > t) return;
	for (int i = x; i < n; i++){
		if (!used[i])
		if (arr[i] <= t - sum){
			sum += arr[i];
			used[i] = true;
			temp.push_back(arr[i]);
			backtrack(i + 1, temp);
			temp.pop_back();
			used[i] = false;
			sum -= arr[i];
		}
	}
}
int main()
{
	cin >> t >> n;
	while (n != 0){
		int val;
		printf("Sums of %d:\n", t);
		vector <int> temp;
		solutions.clear();
		mymap.clear();
		temp.clear();
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			used[i] = false;
		}
		sum = 0;

		backtrack(0, temp);
		if (!solutions.size()) {
			printf("NONE\n");
		}
		for (int i = 0; i<solutions.size(); i++) {
			for (int j = 0; j<solutions[i].size(); j++) {
				if (!j) printf("%d", solutions[i][j]);
				else printf("+%d", solutions[i][j]);
			}
			printf("\n");
		}
		cin >> t >> n;
	}
	system("pause");
	return 0;
}