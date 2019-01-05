#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int l, m, temp, counter = 0, weight = 0;
		cin >> l >> m;
		l *= 100;
		string direction = "left", temp_direction;
		queue<int> left;
		queue<int> right;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp >> temp_direction;
			if (temp_direction == "left")
				left.push(temp);
			else
				right.push(temp);
		}
		while (!left.empty() || !right.empty())
		{
			if (direction == "left")
			{
				if (!left.empty())	
					if (left.front() + weight < l)
					{
						weight += left.front();
						left.pop();
					}
					else
					{
						direction = "right";
						counter++;
						weight = 0;
					}
				else
				{
					direction = "right";
					counter++;
					weight = 0;
				}
			}
			else
			{
				if (!right.empty())
					if (right.front() + weight < l)
					{
						weight += right.front();
						right.pop();
					}
					else
					{
						direction = "left";
						counter++;
						weight = 0;
					}
				else
				{
					counter++;
					direction = "left";
					weight = 0;
				}
			}
		}
		cout << ++counter << endl;
	}
	system("pause");
	return 0;
}