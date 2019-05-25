#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

const int N = 1e6 + 3;
char buffer[N];
string A, B;

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", buffer);
	A = buffer;
	scanf("%s", buffer);
	B = buffer;
	int zeroCounter = 0;
	int twoZerosCounter = 0;
	for (int i = 0; i < n; ++i) 
		if (A[i] == '0')
		{
			if (B[i] == '0') ++twoZerosCounter;
			++zeroCounter;
		}
	
	long long res = 0;
	for (int i = 0; i < n; ++i)
		if (A[i] == '1')
			if (B[i] == '0')
				res += zeroCounter;
			else
				res += twoZerosCounter;
	printf("%lld", res);
	return 0;
}