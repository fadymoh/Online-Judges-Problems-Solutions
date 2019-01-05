#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
using namespace std;

char numbers[10][8] = {
	"YYYYYYN",//0
	"NYYNNNN",//1
	"YYNYYNY",//2
	"YYYYNNY",//3
	"NYYNNYY",//4
	"YNYYNYY",//5
	"YNYYYYY",//6
	"YYYNNNN",//7
	"YYYYYYY",//8
	"YYYYNYY",//9
};
int main()
{
	char input[10][8];
	int i, j, k, n;
	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; i++)
			cin >> input[i];
		int flag = 0;

		for (i = 9; i >= n - 1; i--){
			char bad[10] = { };
			for (j = 0; j < n; j++){
				for (k = 0; k < 7; k++){
					if (bad[k] && input[j][k] == 'Y') break;
					if (input[j][k] == 'N' && numbers[i - j][k] == 'Y') bad[k] = 1;
					else if (input[j][k] == 'Y' && numbers[i - j][k] == 'N') break;
				}
				if (k != 7) break;
			}
			if (j == n) {
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("MIS");
		puts("MATCH");
	}
	system("pause");
	return 0;
}