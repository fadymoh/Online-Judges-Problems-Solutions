#include <iostream>
using namespace std;
int n;
int arr[15];
bool bruteForce(int ind, int sum)
{
	if (ind == n)
		return sum == 0;
	if (bruteForce(ind + 1, sum + arr[ind])) return true;
	if (bruteForce(ind + 1, sum - arr[ind])) return true;
	return false;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	if (bruteForce(0, 0))
		cout << "YES\n";
	else
		cout << "NO\n";

}