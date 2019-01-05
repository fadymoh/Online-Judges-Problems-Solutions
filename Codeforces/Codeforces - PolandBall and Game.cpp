#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
unordered_set<string> polandBall;
unordered_set<string> enemyBall;
vector<string> commonWordsForOptimalSolution;
bool polandTurn()
{
	if (polandBall.size() == 0) return true;
	if (commonWordsForOptimalSolution.size() != 0)
	{
		string temp = commonWordsForOptimalSolution[commonWordsForOptimalSolution.size() - 1];
		commonWordsForOptimalSolution.pop_back();
		enemyBall.erase(enemyBall.find(temp));
		polandBall.erase(polandBall.find(temp));
	}
	else // there is no common words!
	{
		polandBall.erase(polandBall.begin());
	}
	return false;
}
bool enemyTurn()
{
	if (enemyBall.size() == 0) return true;
	if (commonWordsForOptimalSolution.size() != 0)
	{
		string temp = commonWordsForOptimalSolution[commonWordsForOptimalSolution.size() - 1];
		commonWordsForOptimalSolution.pop_back();
		polandBall.erase(polandBall.find(temp));
		enemyBall.erase(enemyBall.find(temp));
	}
	else // there is no common words!
	{
		enemyBall.erase(enemyBall.begin());
	}
	return false;
}
int main()
{
	int poland, enemy;
	string temp;
	cin >> poland >> enemy;
	for (int i = 0; i < poland; ++i)
	{
		cin >> temp;
		polandBall.insert(temp);
	}
	for (int i = 0; i < enemy; ++i)
	{
		cin >> temp;
		if (polandBall.find(temp) != polandBall.end()) commonWordsForOptimalSolution.push_back(temp);
		enemyBall.insert(temp);
	}
	bool polandWins = false;
	while (true)
	{
		if (polandTurn()) // poland have no more moves
		{
			break;
		}
		if (enemyTurn())  //means enemy have no more moves
		{
			polandWins = true;
			break;
		}
	}
	if (polandWins) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}