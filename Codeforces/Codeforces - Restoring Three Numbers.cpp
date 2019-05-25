#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[4];
	scanf("%d %d %d %d", arr, arr + 1, arr + 2, arr + 3);
	sort(arr, arr + 4);
	printf("%d %d %d", arr[3] - arr[0], arr[3] - arr[1], arr[3] - arr[2]);
	return 0;
}