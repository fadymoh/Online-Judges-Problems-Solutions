#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[5];
bool backtrack(int index, int total)
{
	if (index == 5) return total == 23;

	int value = arr[index];

	if (backtrack(index + 1, total + value)) return true;
	if (backtrack(index + 1, total - value)) return true;
	if (backtrack(index + 1, total * value)) return true;

	return false;
}
int main()
{
	int x;
	while (true)
	{
		cin >> x;
		arr[0] = x;
		for (int i = 1; i < 5; ++i)
			cin >> arr[i];
		if (arr[0] == 0) break;
		bool flag = false;
		sort(arr, arr + 5);
		do {
			if (backtrack(1, arr[0])) {
				flag = true;
				break;
			}
		} while (next_permutation(arr, arr + 5));
		if (flag) cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
	system("pause");
	return 0;
}