#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int>   vi;
vi vertices, dfs_num;
vector<vector <int> > graph;
int connections;
bool Node_Exist(int x){
	for (int i = 0; i < vertices.size(); i++){
		if (vertices[i] == x)
			return true;
	}
	return false;
}
void dfs(int x){
	if (Node_Exist(x))
	{
		dfs_num[x] = 1;
		connections++;
		for (int i = 0; i < graph[x].size(); i++)
			if (dfs_num[graph[x][i]] == -1)
				dfs(graph[x][i]);

	}
	else return;
}
int main()
{
	int n;
	string input;
	cin >> n;
	while (n--){
		
		graph.assign(26, vi());
		cin >> input;
		while (input[0] != '*'){
			int first = input[1] - 65, second = input[3] - 65;
			graph[first].push_back(second);
			graph[second].push_back(first);
			cin >> input;
		}
		cin >> input;
		for (int i = 0; i < input.size(); i++){
			if (isalpha(input[i])) vertices.push_back(input[i] - 65);
		}
		dfs_num.assign(26, -1);
		int total_trees = 0, total_acrons = 0;
		for (int x = 0; x < graph.size(); x++)
		{
			if (Node_Exist(x) && dfs_num[x] == -1){
				connections = 0;
				dfs(x);
				if (connections > 1)
					total_trees++;
				else
					total_acrons++;
			}
		}
		cout << "There are " << total_trees << " tree(s) and " << total_acrons << " acorn(s)." <<endl;
		vertices.clear();
	}
	system("pause");
	return 0;
}