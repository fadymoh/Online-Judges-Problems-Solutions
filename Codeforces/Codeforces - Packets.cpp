#include <iostream>
using namespace std;

int main()
{
	int n, counter = 0, decrement = 1, sum;
	cin >> n;
	decrement = sum = n / 2;
	while (n > 0)
	{
		++counter;
		n /= 2;
	}
	cout << counter << endl;
	return 0;
}