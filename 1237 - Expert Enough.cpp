#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct mystruct{
	string Maker;
	int low, high;
};

int main()
{
	int T, D, Q, val;
	mystruct x;
	string xx;

	cin >> T;
	while (T--){
		cin >> D;
		vector <mystruct> myvector;
		for (int i = 0; i < D; i++){
			cin >> x.Maker >> x.low >> x.high;
			myvector.push_back(x);
		}
		cin >> Q;
		for (int i = 0; i < Q; i++){
			cin >> val;
			int counter = 0;
			for (int j = 0; j < myvector.size(); j++){
				if (myvector[j].low <= val && myvector[j].high >= val) {
					counter++;
					xx = myvector[j].Maker;
				}
			}
			if (counter > 1 || counter == 0) cout << "UNDETERMINED" << endl;
			else 
				cout << xx << endl;
		}
	if (T)	cout << endl;
	}
	system("pause");
	return 0;
}