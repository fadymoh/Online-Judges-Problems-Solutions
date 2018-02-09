#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;
struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};
priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string x;
	while (getline(cin, x)){
		if (x == "Game Over") break;
		rep(i, 0, x.size() - 1) x.erase(remove(x.begin(), x.end(), ' '), x.end());
		int sum = 0, strike_counter = 0, frames = 1, rolls = 0, arr[30];
		vector <pair<bool, bool>> mybool(30);
		for (int i = 0; i < x.length(); i++){
			bool strike = false, spare = false;
			int count = 0;
			if (x[i] == 'X') { strike = true; count = 10; frames++; rolls = 0; }
			else if (x[i] == '/') { spare = true; count = 10 - arr[i - 1]; frames++; rolls = 0; }
			else {
				count = x[i] - '0';
				rolls++;
			}
			if (rolls == 2){
				frames++;
				rolls = 0;
			}
			pair <bool, bool> temp;
			if (frames <= 10) temp = make_pair(strike, spare);
			else temp = make_pair(false, false);
			arr[i] = count;
			mybool[i] = temp;
		}
		for (int i = 0; i < x.length(); i++){
			if (mybool[i].first) arr[i] += arr[i + 1] + arr[i + 2];
			else if (mybool[i].second) arr[i] += arr[i + 1];
			sum += arr[i];
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}