#include <iostream>
#include <string>
using namespace std;
int get_binary(int bin) {
	string output = "";
	int val = 0;
	for (int i = 0; i < 32; i += 8)
	{
		val |= ((bin >> i & 0x000000FF) << (24 - i));

		bin >> 1;
	}

	return val;
}
int main()
{
	int n;
	while (cin >> n, !cin.eof())
	{
		int returning = get_binary(n);
		cout << n << " converts to " << returning << endl;
	}
}