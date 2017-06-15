#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int> myvector;
	int input;
	cin >> input;
	do {
		myvector.push_back(input);
		for (int i = 0; i < myvector.size(); i++) if (myvector[i] > input) swap(myvector[i], myvector[myvector.size() - 1]);

		if (myvector.size() % 2 != 0) cout << myvector[myvector.size() / 2] << endl;

		else cout << int((myvector[myvector.size() / 2] + myvector[(myvector.size() / 2) - 1]) / 2) << endl;
	} while (cin >> input);
	system("pause");
	return 0;
}