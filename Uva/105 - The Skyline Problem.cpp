#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>
using namespace std;

int main()
{
	int arr[10005] = {0}, left, height, right, rightmost = 0;
	while (cin >> left >> height >> right){
		for (int i = left; i < right; i++)
			if (height > arr[i]) arr[i] = height;
			if (right > rightmost) rightmost = right;
	}
	for (int i = 1; i < rightmost; i++)
	if (arr[i] != arr[i - 1]) cout << i << " " << arr[i] << " ";
	cout << rightmost << " 0"<<endl;
	system("pause");
	return 0;
}
