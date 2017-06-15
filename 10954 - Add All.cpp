#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int input, values, smallest_value = 0, temp;

	cin >> input;
	do{
		if (input == 0) break;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= input; i++){
			cin >> values;
			q.push(values);
		}
		int cost = 0;
		while (q.size() > 1){
			temp = q.top();
			q.pop();
			temp += q.top();
			q.pop();
			q.push(temp);
			cost += temp;
		}
		cout << cost << endl;
		cin >> input;
	} while (true);
	system("pause");
	return 0;
}