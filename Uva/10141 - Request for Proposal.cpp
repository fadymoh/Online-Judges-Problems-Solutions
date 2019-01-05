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
#include <unordered_map>
#include <iomanip>
using namespace std;
struct comparatorr {
	bool operator()(pair <string, float> i, pair <string, float> j) {
		return i.second > j.second;
	}
};
bool sortbysec(const pair<string, float> &a,
	const pair<string, float> &b)
{
	return (a.second > b.second);
}
//priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int requirment, proposals, counter = 1;
	while (cin >> requirment >> proposals, requirment != 0 && proposals != 0)
	{
		string temp;
	//	if (requirment != 0 && proposals != 0 && counter != 1)cout << endl << endl;
		vector <pair <string, double>> myvector;
		vector <pair <string, double>> myproposals;
		map <string, double> mymap;
		for (int i = 0; i < requirment;  i++){
			cin.ignore();
			getline(cin, temp);
		}
		string company_name;
		double  requirments_met, req = -1;
		double price, price_min = -1;
		string ans;
		rep(i, 1, proposals)
		{
			getline(cin, company_name);
			cin >> price >> requirments_met;
			if (requirments_met > req)
			{
				ans = company_name;
				req = requirments_met;
				price_min = price;
			}
			else if (requirments_met == req && price_min > price)
			{
				ans = company_name;
				req = requirments_met;
				price_min = price;
			}
			for (int j = 0; j <= requirments_met; j++) getline(cin, temp);
			
		}
		if (counter > 1)
			cout << endl;
		cout << "RFP #" << counter++ << endl;
		cout << ans << endl;

	}

	//system("pause");
	return 0;
}