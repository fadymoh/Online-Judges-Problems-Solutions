#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100 + 5;
char buffer[N];
string in;
int arr[4];
unordered_map<char, int> myMap;

int main()
{
	scanf("%s", buffer);
	in = buffer;
	int sz = in.length();
	int idxR, idxB, idxY, idxG;
	for (int i = 0; i < sz; ++i)
	{
		switch (in[i])
		{
		case 'R':
			idxR = i;
			break;
		case 'G':
			idxG = i;			
			break;
		case 'Y':
			idxY = i;
			break;
		case 'B':
			idxB = i;			
			break;
		}
	}
	idxB %= 4; idxG %= 4; idxR %= 4; idxY %= 4;
	arr[idxB] = 'B';
	arr[idxG] = 'G';
	arr[idxR] = 'R';
	arr[idxY] = 'Y';
	for (int i = 0; i < sz; ++i)
	{
		if (in[i] == '!')
		{
			++myMap[arr[i % 4]];
		}
	}
	printf("%d %d %d %d", myMap[arr[idxR]], myMap[arr[idxB]], myMap[arr[idxY]], myMap[arr[idxG]]);
	return 0;
}