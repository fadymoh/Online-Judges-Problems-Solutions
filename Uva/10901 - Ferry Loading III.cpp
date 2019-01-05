#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

bool compr(const pair<int, int> &one, const pair <int, int> &two)
{
	return one.second < two.second;
}

int main()
{
	int t;
	cin >> t;
	while (t--){
		int n, time, m, current_time = 0, temp;
		string bank;
		queue< pair<int, int> > left;
		queue< pair<int, int> > right;
		cin >> n >> time >> m;
		for (int i = 0; i < m; ++i){
			cin >> temp >> bank;
			if (bank == "left")
				left.push(make_pair(temp, i));
			else
				right.push(make_pair(temp, i));
		}
		bank = "left";
		bool flag = false;
		vector<pair<int, int>> mOutput;
		int weight = 0;
		while (!left.empty() || !right.empty())
		{
			if (bank == "left") {
				if (!left.empty() && left.front().first <= current_time)
				{
					bank = "left";
				}
				else if (!right.empty() && right.front().first <= current_time)
				{
					bank = "right";
					current_time += time;
				}
			}
			else
			{
				if (!right.empty() && right.front().first <= current_time)
					bank = "right";
				else if (!left.empty() && left.front().first <= current_time) {
					bank = "left";
					current_time += time;
				}
			}
			flag = false;
			if (bank == "left") {
				pair <int, int> temp;
				while (weight < n && !left.empty()) {
					temp = left.front();
					if (temp.first <= current_time) {
						weight++;
						left.pop();
						mOutput.push_back(make_pair(current_time + time, temp.second));
						flag = true;
					}
					else break;
				}
				if (flag) {
					current_time += time;
					weight = 0;
					bank = "right";
				}
				else
					current_time++;
			}
			else {
				pair <int, int> temp;
				while (weight < n && !right.empty()) {
					temp = right.front();
					if (temp.first <= current_time ){
						weight++;
						right.pop();
						mOutput.push_back(make_pair(current_time + time, temp.second));
						flag = true;
					}
					else break;
				}
				if (flag) {
					current_time += time;
					weight = 0;
					bank = "left";
				}
				else
					current_time++;
			}
		}
		sort(mOutput.begin(), mOutput.end(), compr);
		for (int i = 0; i < mOutput.size(); ++i)
			cout << mOutput[i].first << endl;
		if (t)
		cout << endl;
	}
	system("pause");
	return 0;
}