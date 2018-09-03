#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int arr[1001];
	bool visited[1001];
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, false, sizeof(visited));
		int j = i;
		while (!visited[j]) visited[j] = true, j = arr[j];
		cout << j <<((i == n) ? '\n':' ');
	}
	return 0;
}