#include <iostream>
using namespace std;
int n, mArr[20];
bool taken[20];
int counter = 0;
bool isPrime(int temp)
{
	for (int i = 2; i <= sqrt(temp); ++i)
		if (temp % i == 0) return false;
	return true;
}
void backtrack(int x)
{
	if (x == n+1 && isPrime(mArr[n] + mArr[n+1]))
	{
		for (int i = 1; i < n; ++i)
			cout << mArr[i] << ' ';
		cout << mArr[n] << endl;
		return;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!taken[i])
		{
			if (isPrime(mArr[x-1] + i))
			{
				taken[i] = true;
				mArr[x] = i;
				backtrack(x + 1);
				taken[i] = false;
			}
		}
	}
}
int main()
{
	while (cin >> n)
	{
		if (counter)
			cout << endl;
		for (int i = 0; i < 20; i++) {
			taken[i] = 0;
		}
		mArr[1] = mArr[n+1] = 1;
		cout << "Case " << ++counter << ":\n";
		backtrack(2);
	}
	system("pause");
	return 0;
}