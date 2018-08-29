#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int W, H, N;
	int ToFill, Filled;
	cin >> W >> H >> N;
	while (W&&H)
	{
		ToFill = W * H;
		Filled = 0;
		bool board[500][500] = { false };
		for (size_t i = 0; i < N; i++)
		{
			int X1, X2, Y1, Y2;
			cin >> X1 >> Y1 >> X2 >> Y2;
			for (size_t j = min(X1, X2); j <= max(X1, X2); j++)
				for (size_t k = min(Y1, Y2); k <= max(Y1, Y2); k++)
				{
					if (!board[j][k])
					{
						Filled++;
						board[j][k] = true;
					}
				}
		}
		int EmptySpots = ToFill - Filled;
		if (EmptySpots == 0)
			cout << "There is no empty spots." << endl;
		else if (EmptySpots == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << EmptySpots << " empty spots." << endl;

		cin >> W >> H >> N;
	}
	return 0;
}