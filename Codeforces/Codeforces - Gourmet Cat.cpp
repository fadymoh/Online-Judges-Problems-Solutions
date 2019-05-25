#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int days[7] = { 1,0,0,1,2,0,2 };

int noOFDays(int fish, int rabbit, int chicken, int start)
{
	bool finished = false;
	int i = start;
	for (; i < start + 7 && !finished;i++)
	{
		switch (days[i % 7])
		{
			case 0: //fish
				if (fish == 0)
					finished = true;
				else
					--fish;
				break;
			case 1: //rabbit
				if (rabbit == 0)
					finished = true;
				else
					--rabbit;
				break;
			case 2: //rabbit
				if (chicken == 0)
					finished = true;
				else
					--chicken;
				break;
		}
	}
	return i - start-1;
}

int main()
{
	int fish, rabbit, chicken;
	scanf("%d %d %d", &fish, &rabbit, &chicken);
	int fullWeeks = min(fish / 3, min(rabbit / 2, chicken / 2));
	int mx = -1;
	for (int i = 0; i < 7; ++i)
	{
		mx = max(mx, 7*fullWeeks + noOFDays(fish - fullWeeks*3, rabbit - fullWeeks*2, chicken - fullWeeks*2, i));
	}
	printf("%d\n", mx);
	return 0;
}