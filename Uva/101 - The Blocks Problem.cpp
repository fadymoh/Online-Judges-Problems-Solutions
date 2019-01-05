#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
/*The valid commands for the robot arm that manipulates blocks are :
• move a onto b
where a and b are block numbers, puts block a onto block b after returning any blocks that are
stacked on top of blocks a and b to their initial positions.
• move a over b
where a and b are block numbers, puts block a onto the top of the stack containing block b, after
returning any blocks that are stacked on top of block a to their initial positions.
• pile a onto b
where a and b are block numbers, moves the pile of blocks consisting of block a, and any blocks
that are stacked above block a, onto block b.All blocks on top of block b are moved to their
initial positions prior to the pile taking place.The blocks stacked above block a retain their order
when moved.
• pile a over b
where a and b are block numbers, puts the pile of blocks consisting of block a, and any blocks
that are stacked above block a, onto the top of the stack containing block b.The blocks stacked
above block a retain their original order when moved.
• quit
terminates manipulations in the block world.*/typedef list<vector<int> >::iterator it;int main(){	map <int, stack <int> > mymap;	int n, a, b;	cin >> n;	string first, second;	for (int i = 1; i <= n; i++){		mymap[i].push(i);	}	mymap[1].push(10);	cout << " 5ara  " << endl;	/*for (int i = 0; i < n; i++){		cin >> first >> a >> second >> b;		if (a != b)		{			if (first == "move"){				if (second == "onto"){				}				else {				}			}			else{				if (second == "onto"){				}				else {				}			}		}	}*/	system("pause");	return 0;}