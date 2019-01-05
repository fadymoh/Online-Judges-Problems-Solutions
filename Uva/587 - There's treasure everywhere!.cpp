#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi = 2 * acos(0);

int main()
{
	string temp;
	int map_counter = 0;
	while (cin >> temp, temp != "END")
	{
		double x = 0, y = 0;
		string val = "", dest = "";
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp[i] >= '0' && temp[i] <= '9')
				val.push_back(temp[i]);
			else if (temp[i] != ',' && temp[i] != '.')
				dest.push_back(temp[i]);
			else if (temp[i] == ',' || temp[i] == '.')
			{
				if (dest == "N"){
					y += stoi(val);
				}
				else if (dest == "NE"){
					y += (stoi(val) * sin(45 * pi / 180));
					x += (stoi(val) * cos(45 * pi / 180));
				}
				else if (dest == "E") {
					x += stoi(val);
				}
				else if (dest == "SE") {
					y -= (stoi(val) * sin(45 * pi / 180));
					x += (stoi(val) * cos(45 * pi / 180));
				}
				else if (dest == "S") {
					y -= stoi(val);
				}
				else if (dest == "SW") {
					y -= (stoi(val) * sin(45 * pi / 180));
					x -= (stoi(val) * cos(45 * pi / 180));
				}
				else if (dest == "W") {
					x -= stoi(val);
				}
				else if (dest == "NW") {
					x -= (stoi(val) * cos(45 * pi / 180));
					y += (stoi(val) * sin(45 * pi / 180));
				}
				dest = "";
				val = "";
			}
		}
		cout << "Map #" << ++map_counter << "\nThe treasure is located at ("
			 << fixed << setprecision(3) << x << ',' << y << ").\n";
		cout << "The distance to the treasure is " << fixed << setprecision(3) << sqrt(x*x + y * y) << ".\n\n";
	}

	return 0;
}