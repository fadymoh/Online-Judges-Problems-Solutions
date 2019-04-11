#include <iostream>
using namespace std;
int n, counter = 0;
int ** mArr;
void backtrack(int x, int y)
{
	if (x == n - 1 && y == n - 1)
	{
		++counter;
		return;
	}
	if (x < n && x >= 0 && y < n && y >= 0)
	{
		if (mArr[x][y]) return;
		mArr[x][y] = 1;
		backtrack(x + 1, y);
		backtrack(x, y + 1);
		backtrack(x - 1, y);
		backtrack(x, y - 1);
		mArr[x][y] = 0;
	}
	return;
}

int main()
{
	cin >> n;
	mArr = new int *[n];
	for (int i = 0; i < n; ++i)
		mArr[i] = new int[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mArr[i][j];
	backtrack(0, 0);
	cout << counter << endl;
	system("pause");
	return 0;
}