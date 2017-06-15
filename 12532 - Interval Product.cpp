#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
	vi ft;

public:
	FenwickTree() {}
	// initialization: n + 1 zeroes, ignore index 0
	FenwickTree(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) {                                     // returns RSQ(1, b)
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int rsq(int a, int b) {                              // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) {                    // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int main()
{
	
	int n, m, val1, val2, input;
	char command;
	int arr[100005];
	//cin >> n >> m;
	while (cin >> n >> m){
		FenwickTree mynegtree(n), myzerotree(n);
		for (int i = 1; i <= n; i++){
			cin >> input;
			arr[i] = input;
			if (input < 0) mynegtree.adjust(i, 1);
			else if (input == 0) myzerotree.adjust(i, 1);
		}
		for (int i = 1; i <= m; i++){
			cin >> command >> val1 >> val2;
			if (command == 'C'){
				if (val2 > 0)
{
					if (arr[val1] == 0) myzerotree.adjust(val1, -1);
					if (arr[val1] < 0) mynegtree.adjust(val1, -1);
				}
				else if (val2 == 0){
					if (arr[val1] != 0) myzerotree.adjust(val1, 1);
					if (arr[val1] < 0) mynegtree.adjust(val1, -1);
				}
				else{
					if (arr[val1] == 0) myzerotree.adjust(val1, -1);
					if (arr[val1] >= 0) mynegtree.adjust(val1, 1);
				}
				
				arr[val1] = val2;
			}
			else{
				int neg = mynegtree.rsq(val1, val2);
				int zero = myzerotree.rsq(val1, val2);
				if (zero != 0) cout << 0;
				else if (neg % 2 != 0) cout << '-';
				else cout << '+';
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}