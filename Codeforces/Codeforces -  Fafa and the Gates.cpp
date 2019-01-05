#include <iostream>
#include <string>
using namespace std;
int whichKingdom(int x, int y)
{
	if (x == y) return 2;
	return y > x; //upper kingdom
}
int main()
{
	int n, x = 0, y = 0;
	string in;
	cin >> n;
	cin >> in;
	bool upperKingdom = false;
	if (in[0] == 'U') upperKingdom = true, ++y;
	else ++x;
	int counter = 0;
	for (int i = 1; i < n; ++i)
	{
		if (in[i] == 'U')
		{
			y++;
			int flag = whichKingdom(x, y); // true then upper kingdom
			if (flag == 2) continue;
			if (!upperKingdom && flag) // i switched to upper kda
			{
				++counter;
				upperKingdom = true;
			}
			else if (upperKingdom && !flag) // switched to down
			{
				++counter;
				upperKingdom = false;
			}
		}
		else
		{
			++x;
			bool flag = whichKingdom(x, y);
			if (flag == 2) continue;
			if (upperKingdom && !flag)
			{
				++counter;
				upperKingdom = false;
			}
			else
			{
				++counter;
				upperKingdom = true;
			}
		}
	}
	cout << counter << endl;
	return 0;
}