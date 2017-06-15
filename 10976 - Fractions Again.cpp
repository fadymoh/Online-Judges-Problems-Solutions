#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
struct mystruct{
	int x, y, sum;
};
struct comparator {
	bool operator()(mystruct i, mystruct j) {
		return i.sum < j.sum;
	}
};
int main()
{
	priority_queue<mystruct, vector<mystruct>, comparator> myvector;
	int k;
	while (cin >> k){
		for (int x = k + 1; x <= 2 * k; x++)
			if ((k*x) % (x - k) == 0){
				mystruct v; v.y = x; v.x = (k*x) / (x - k); v.sum = v.x + v.y;
				myvector.push(v);
			}	
			cout << myvector.size() << endl;
		for (int i = 0; !myvector.empty(); i++){
			mystruct v = myvector.top();
			myvector.pop();
			cout << "1/" << k << " = 1/" << v.x << " + 1/" << v.y << endl;
		}
	}
	system("pause");
	return 0;
}