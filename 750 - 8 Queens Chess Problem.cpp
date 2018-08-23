#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int TC, a, b, row[8], lineCounter;

bool place(int r, int c)
{
	for (int i = 0; i < c; ++i)
	{
		if (row[i] == r || abs(row[i] - r) == abs(i - c))
			return false;
	}
	return true; // i can place it there
}
void backtrack(int c)
{
	if (c == 8 && row[b] == a)
	{
		//base case
		printf("%2d      %d", ++lineCounter, row[0] + 1);
		for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
		printf("\n");
	}

	for (int i = 0; i < 8; ++i)
	{
		if (place(i, c))
		{
			row[c] = i;
			backtrack(c + 1);
		}
	}
}
int main()
{
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b); a--; b--; // switch to 0-based indexing
		//memset(row, 0, sizeof row); lineCounter = 0;
		lineCounter = 0;
		for (int i = 0; i < 8; ++i)
			row[i] = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0); // generate all possible 8! candidate solutions
		if (TC) printf("\n");
	}
	return 0;
}