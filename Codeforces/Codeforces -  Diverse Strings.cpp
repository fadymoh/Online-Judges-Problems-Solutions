#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool isDiverse(const string & word)
{
	int dup[28] = {};
	int sz = word.length();
	for (int i = 0; i < sz; ++i) {
		if (dup[word[i] - 'a']++) return false;
	}
	//0000111001
	int partitions = 0;
	bool zero = true;
	for (int i = 0; i < 28; ++i)
	{
		if (dup[i] == 1 && zero)
		{
			++partitions;
			zero = false;
		}
		if (dup[i] == 0)
			zero = true;
	}
	return partitions == 1;
}
char buffer[105];
int main()
{
	int n;
	string in;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", buffer);
		in = buffer;
		if (isDiverse(in)) puts("YES");
		else puts("NO");	
	}

	return 0;
}