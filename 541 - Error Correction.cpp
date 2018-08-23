#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		bool arr[101][101] = {0};
		int sum_vert = 0 , sum_horz = 0;
		bool horz[101] = { 0 };
		int vert[101] = { 0 };
		int first_horz = -1, first_vert = -1, odd_counter_horizontal = 0, odd_counter_vertical = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum_horz = 0;
			for (int j = 1; j <= n; ++j)
			{
				cin >> arr[i][j];
				sum_horz += arr[i][j];
				vert[j] += arr[i][j];
			}
			horz[i] = sum_horz % 2; //even or odd
			if (horz[i]) {
				if (first_horz == -1)
					first_horz = i;
				odd_counter_horizontal++;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			vert[i] %= 2;
			if (vert[i]) {
				if (first_vert == -1)
					first_vert = i;
				odd_counter_vertical++;
			}
		}
		if (odd_counter_horizontal >= 2 || odd_counter_vertical >= 2)
			cout << "Corrupt\n";
		else if (odd_counter_horizontal + odd_counter_vertical == 0)
			cout << "OK\n";
		else
			cout << "Change bit (" << first_horz << "," << first_vert << ")\n";
	}

	system("pause");
	return 0;
}