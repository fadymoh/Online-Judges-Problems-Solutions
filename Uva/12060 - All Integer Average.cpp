#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <cmath>
#include <iomanip>
using namespace std;
//rep(i, 0, changed.size() - 1) changed[i].erase(remove(changed[i].begin(), changed[i].end(), ' '), changed[i].end());
struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};
priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int gcd(int a, int b)
{
	if (b != 0) return gcd(b, a%b);
	else return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int counter = 1;
	while (cin >> n, n != 0)
	{
		int avg = 0, x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			avg += x;
		}
		int a = avg%n;
		int b = n;
		int gcdd = gcd(a, b);
		avg /= n;
		a /= gcdd;
		b /= gcdd;
		cout << "Case " << counter++ << ":\n";
		string temp2 = to_string(avg);
		string temp = to_string(abs(b));

		int length = temp.length();
		int length2 = temp2.length();
		if (avg < 0) {
			temp2.insert(1, 1, ' ');
			length2++;
		}
		if (a != 0) //then we have a fraction
		{
			bool flag = false;
			if ((a < 0 || b < 0) && avg == 0) flag = true;
			if (flag) length2 += 2;
			if (avg == 0)
			{
				length2--;
				cout << setw(length + length2) << abs(a) << endl;
			}
			else
				cout << setw(length + length2) << abs(a) << endl << temp2;
			if (flag) cout << "- ";
			for (int i = 0; i < length; i++)
				cout << '-';
			cout << endl << setw(length + length2) << abs(b) << endl;
		}
		else cout << temp2 << endl;
	 }
	system("pause");
	return 0;
}