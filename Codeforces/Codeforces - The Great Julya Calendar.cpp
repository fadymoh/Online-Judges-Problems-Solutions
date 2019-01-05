#include <iostream>
#include <algorithm>
using namespace std;
int max_digit(int digit)
{
	int maxx = -1;
	while (digit != 0)
	{
		int temp = digit % 10;
		digit /= 10;
		maxx = max(maxx, temp);
	}
	return maxx;
}
int main()
{
	int n;
	cin >> n;
	int counter = 0;
	while (n != 0)
	{
		n -= max_digit(n);
		counter++;
	}
	cout << counter << endl;
}