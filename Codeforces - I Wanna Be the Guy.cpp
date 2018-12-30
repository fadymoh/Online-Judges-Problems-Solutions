#include <iostream>
using namespace std;
int arr[101], n;

int main()
{
	int x, y;
	cin >> n;
	cin >> x;
	int temp;
	for (int i = 0; i < x; ++i)
	{
		cin >> temp;
		++arr[temp];
	}
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		cin >> temp;
		++arr[temp];
	}
	bool flag = false;
	for (int i = 1; i <= n; ++i)
		if (!arr[i]) flag = true;
	if (flag) cout << "Oh, my keyboard!\n";
	else cout << "I become the guy.\n";
	return 0;
}