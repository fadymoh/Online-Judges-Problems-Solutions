#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct contestant{
	int incorrect[10];
	int solved = 0;
	int penalty = 0;
	bool print = false;
	int player_number;
};
contestant arr[101];
	bool opr (const contestant& first, const contestant& second)
	{
		if (first.solved != second.solved) return first.solved > second.solved;
		else if (first.penalty != second.penalty) return first.penalty < second.penalty;
		else return first.player_number < second.player_number;
	}
int main()
{
	int t;
	cin >> t;
	getchar();
	getchar();
	for (int i = 0; i < t; ++i)
	{
		int problemNumber, time, playerNumber;
		char contestantNumber[50];
		while (gets_s(contestantNumber) ) {
			char command[10];
			if (!strcmp(contestantNumber, ""))
				break;
			sscanf(contestantNumber, "%d %d %d %s", &playerNumber, &problemNumber, &time, command);

			arr[playerNumber].print = true;
			arr[playerNumber].player_number = playerNumber;
			if (command[0] == 'I')
			{
				++arr[playerNumber].incorrect[problemNumber];
			}
			else if (command[0] == 'C')
			{
				if (arr[playerNumber].incorrect[problemNumber] > -1)
				{
					arr[playerNumber].penalty += arr[playerNumber].incorrect[problemNumber] * 20 + time;
					arr[playerNumber].solved++;
				}
				arr[playerNumber].incorrect[problemNumber] = -1000000;
			}
		}
		sort(arr + 1, arr + 101, opr);
		for (int j = 1; j < 101; ++j)
		{
			if (arr[j].print)
				cout << arr[j].player_number << ' ' << arr[j].solved << ' ' << arr[j].penalty << endl;
			arr[j] = contestant();
		}

		if (i < t - 1) cout << "\n";
	}
	system("pause");
	return 0;
}