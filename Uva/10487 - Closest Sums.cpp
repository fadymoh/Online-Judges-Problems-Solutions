#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, x, Q, case_counter = 1;
	cin >> n;
	while (n != 0){
		int  query_counter = 1;
		cout << "Case " << case_counter++ << ":" << endl;
		vector <int > myvector;
		for (int i = 0; i < n; i++){
			cin >> x;
			myvector.push_back(x);
		}
		sort(myvector.begin(), myvector.end());
		
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> Q;
			cout << "Closest sum to " << Q << " is ";
			int ans = myvector[0] + myvector[1];
			for (int j = 0; j < myvector.size(); j++){
				for (int k = j + 1; k < myvector.size(); k++){
					 int temp = myvector[j] + myvector[k];
					 if (abs(ans - Q) > abs(temp - Q)) ans = temp;
				}
			}
			cout << ans << "." << endl;
		
		}
		cin >> n;
	}
	system("pause");
	return 0;
}