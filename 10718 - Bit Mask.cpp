#include <iostream>
using namespace std;

int main()
{
	unsigned int n, l, u;
	while (cin >> n, !cin.eof())
	{
		cin >> l >> u;
		int max = -1;
		int temp = u;
		int bits = 0;
		while (temp != 0)
		{
			temp /= 2;
			bits++;
		}

		unsigned int maxx = 0;
		if (l == 0 && n < u)
			cout << u << endl;
		else
		{
			for (int i = 0; i < bits; ++i)
			{
				unsigned int fuck_me = (1 << i) | l;
				if (fuck_me <= u && (fuck_me | n) > maxx) {
					l = fuck_me;
					maxx = fuck_me | n;
				}
			}
			cout << l << endl;
		}
	}
	system("pause");
	return 0;
}