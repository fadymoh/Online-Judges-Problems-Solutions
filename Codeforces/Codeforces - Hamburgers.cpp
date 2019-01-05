#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[3];
long long B, S, C, BPrice, SPrice, CPrice, amount;
bool valid(long long noOfSandwiches)
{
	long long cost = 0;
	long long zero = 0;
	cost += max(noOfSandwiches * arr[0] - B, zero) * BPrice;
	cost += max(noOfSandwiches * arr[1] - S, zero) * SPrice;
	cost += max(noOfSandwiches * arr[2] - C, zero) * CPrice;
	return cost <= amount;
}
int main()
{
	string in;
	cin >> in;
	for (int i = 0; i < in.length(); ++i)
	{
		if (in[i] == 'B') ++arr[0];
		else if (in[i] == 'S') ++arr[1];
		else ++arr[2];
	}
	cin >> B >> S >> C >> BPrice >> SPrice >> CPrice >> amount;
	long long Xl = 0, Xu = 1e12 + 100;
	while (Xl < Xu)
	{
		long long mid = Xl + (Xu - Xl + 1) / 2;
		if (valid(mid))
			Xl = mid;
		else
			Xu = mid - 1;
	}
	cout << Xl << endl;
	return 0;
}