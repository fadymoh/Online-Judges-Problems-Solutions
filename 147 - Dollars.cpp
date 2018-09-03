#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int coins[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10,5 };
int n = 11;
long long memo[12][30001];
long long dp(int type, int value)
{
	long long &ret = memo[type][value];
	if (value == 0) return 1;
	if (value < 0 || type == n) return 0;
	if (ret != -1) return ret;
	
	return ret = dp(type + 1, value) + dp(type, value - coins[type]);
}
int main()
{
	string v;
	memset(memo, -1, sizeof(memo));
	while (cin >> v, v != "0.00")
	{
		int dollars = stoi(v.substr(0, v.find('.')));
		int found = v.find('.');
		int cents = stoi(v.substr(found+1));
		cout << setw(6) << v << setw(17) << dp(0, dollars*100 + cents) << endl;
	}
	return 0;
}