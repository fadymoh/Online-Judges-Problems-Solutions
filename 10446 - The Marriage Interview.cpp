#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef unsigned long long int datatype;
datatype memo[100][100];
int first;
unsigned int second;
datatype trib(int n, int back)
{
	if (n <= 1) return 1;
	datatype &ret = memo[n][back];
	if (ret != 0) return ret;
	ret = 1;
	for (int i = 1; i <= back; i++)
		ret += trib(n - i, back);
	return ret;
}
int main()
{
	int case_counter = 0;
	memset(memo, 0, sizeof memo);
	while (cin >> first >> second, first <= 60)
	{
		cout << "Case " << ++case_counter << ": " << trib(first, second) << endl;
	}
	return 0;
}