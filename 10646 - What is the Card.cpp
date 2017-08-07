#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
int main()
{
	int TC, CC = 1;
	scanf_s("%d", &TC);
	while (TC--){
		string deck[52];
		int arr[52], i, temp;
		rep(i, 0, 51)
			cin >> deck[i];
		
		printf("Case %d: %s\n", CC++, deck[32]);
	}
	system("pause");
	return 0;
}
