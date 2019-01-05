#include <iostream>
using namespace std;
int arr[6];
bool bruteForce(int curr, int first, int second, int countfirst, int countsecond)
{
	if (curr == 6)
		return first == second;
	if (countfirst < 3)
		if (bruteForce(curr + 1, first + arr[curr], second, countfirst + 1, countsecond)) return true;
	if (countsecond < 3)
		if (bruteForce(curr + 1, first, second + arr[curr], countfirst, countsecond + 1)) return true;
	return false;
}
int main()
{
	for (int i = 0; i < 6; ++i)
		cin >> arr[i];
	if (bruteForce(0, 0, 0, 0, 0))
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}