#include <iostream>
using namespace std;

int main()
{
	int R, C, N;
	int case_counter = 0;
	while (cin >> R >> C >> N, R != 0)
	{
		bool rows[10001] = {0}, columns[10001] = { 0 };
		int r, c;
		for (int i = 0; i < N; ++i)
		{
			cin >> r >> c;
			rows[r] = true;
			columns[c] = true;
		}
		cin >> r >> c;
		if (
			(!rows[r] && !columns[c]) ||
			(r < R - 1 && !rows[r + 1] && !columns[c]) ||
			(r > 0 && !rows[r - 1] && !columns[c]) ||
			(c < C - 1 && !rows[r] && !columns[c + 1]) ||
			(c > 0 && !rows[r] && !columns[c - 1])
			)
			cout << "Case " << ++case_counter << ": Escaped again! More 2D grid problems!\n";
		else
			cout << "Case " << ++case_counter << ": Party time! Let's find a restaurant!\n";
	}
	system("pause");
	return 0;
}