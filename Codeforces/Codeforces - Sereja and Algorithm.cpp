#include <iostream>
#include <string>
using namespace std;
int X[100005] = { 0 }, Y[100005] = { 0 }, Z[100005] = { 0 };
int main()
{
	string in;
	cin >> in;
	int m, left, right;
	for (int i = 0; i < in.length(); ++i)
	{
		char temp = in[i];
		switch (temp)
		{
		case 'z':
			Z[i + 1] = Z[i] + 1;
			Y[i + 1] = Y[i];
			X[i + 1] = X[i];
			break;
		case 'y':
			Y[i + 1] = Y[i] + 1;
			Z[i + 1] = Z[i];
			X[i + 1] = X[i];
			break;
		default:
			X[i + 1] = X[i] + 1;
			Z[i + 1] = Z[i];
			Y[i + 1] = Y[i];
		}

	}
	cin >> m;
	while (m--)
	{
		cin >> left >> right;
		--left;
		int noX = X[right] - X[left];
		int noY = Y[right] - Y[left];
		int noZ = Z[right] - Z[left];
		if (right - left == 3)
		{
			if (noX != 1 || noX != noY || noY != noZ)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else if (right - left < 3)
			cout << "YES\n";
		else
		{
			if (abs(noX - noY) > 1 || abs(noY - noZ) > 1 || abs(noX - noZ) > 1)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}

	return 0;
}