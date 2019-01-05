#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const double EPS = 1e-15;
vector <int> positions;
vector <int> velocity;
int n;
//line sweep algorithm
bool valid2(double time)
{
	vector<pair<double, int>> events;
	// generate all the possible events (starting point of an interval, or an end, and the int to say if it is a start or an end)
	for (int i = 0; i < n; ++i)
	{
		events.emplace_back(positions[i] - velocity[i] * time, -1);
		events.emplace_back(positions[i] + velocity[i] * time, 1);
	}
	sort(events.begin(), events.end());
	int count = 0;
	for (auto &e : events)
	{
		count -= e.second;
		if (count == n) return true;
	}
	return false;
}
bool valid(double time)
{
	double l = -1e9, r = 1e10;
	for (int i = 0; i < n; ++i)
	{
		r = min(r, positions[i] + velocity[i] * time);
		l = max(l, positions[i] - velocity[i] * time);
	}
	return r <= l;
}
int main()
{
	cin >> n;
	positions.resize(n);
	velocity.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> positions[i];
	for (int i = 0; i < n; ++i)
		cin >> velocity[i];
	double xl = 0, xu = 1e9;
	for (xu /= 2; xu > EPS; xu /= 2)
	{
		double mid = xl + xu;
		if (valid(mid))
		{
			xl = mid;
		}
	}
	cout << setprecision(10) << fixed << xl + xu << endl;
	return 0;
}