#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
/*struct mystruct{
	int row = 0, col = 0;
};
int arr[9][9];
mystruct queens[9];

bool backtrack(int level){
	if (level == 9) return true;
	int col;
	bool safe = true;
	for (col = 1; col < 9; col++){
		safe = true;
		for (int queen = 1; queen < level; queen++){
			if (queens[queen].col == col || queens[queen].row - queens[queen].col == level - col || queens[queen].row + queens[queen].col == level + col) { safe = false; break; }
		}
	}

	if (safe){
		queens[level].row = level;
		queens[level].col = col;
		if (backtrack(level + 1))
		return true;
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	while (T--){
		int x, y;
		arr[9][9] = { 0 };
		cin >> x >> y;
		queens[x].row = x;
		queens[x].col = y;
		backtrack(1);
		for (int i = 1; i < 9; i++) cout << queens[i].row << " " << queens[i].col << endl;
	}

	system("pause");
	return 0;
}*/
int row[8], x, y, lineCounter;
bool check(int r, int c)
{
	for (int i = 0; i < c; i++)
	if (row[i] == r || abs(i - c) == abs(row[i] - r)) return false;
	return true;
}
void backtrack(int n){
	if (n == 8 && row[y] == x){
		printf("%2d     ", ++lineCounter);
		for (int i = 0; i < 8; i++) printf(" %d", row[i] + 1);
		printf("\n");
		return;
	}
	for (int i = 0; i < 8; i++)
	if (check(i, n)) { row[n] = i; backtrack(n + 1); }

}
int main()
{
	int T;
	cin >> T;
	while (T--){

		cin >> x >> y;
		lineCounter = 0;
		for (int i = 0; i < 8; i++) row[i] = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		x--; y--;
		backtrack(0);
		if (T) printf("\n");
	}
	system("pause");
	return 0;
}