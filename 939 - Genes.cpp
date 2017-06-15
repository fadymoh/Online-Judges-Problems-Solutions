#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
struct mystruct{
	bool parent_entered = false, parent = false, gene_solved = false;
	string gene_type, child, parent1, parent2;
};
void recursive_fn(map<string, mystruct > &mymap, map<string, mystruct >::iterator it)
{
	if (it != mymap.end()){
		if (mymap[it->first].parent == false){
			if (mymap[it->second.parent1].gene_solved == true){
				if (mymap[it->second.parent2].gene_solved == true){
					if (mymap[it->second.parent1].gene_type == "dominant" || mymap[it->second.parent2].gene_type == "dominant"){
						if ((mymap[it->second.parent1].gene_type == "dominant" && mymap[it->second.parent2].gene_type == "recessive") || (mymap[it->second.parent2].gene_type == "dominant" && mymap[it->second.parent1].gene_type == "recessive") || (mymap[it->second.parent2].gene_type == "dominant" && mymap[it->second.parent1].gene_type == "dominant")){
							it->second.gene_type = "dominant";
							it->second.gene_solved = true;
						}
						else{
							it->second.gene_type = "recessive";
							it->second.gene_solved = true;
						}
					} else if (mymap[it->second.parent1].gene_type == "non-existent" || mymap[it->second.parent2].gene_type == "non-existent")	{
						it->second.gene_type = "non-existent";
						it->second.gene_solved = true;
					}
					else{
						it->second.gene_type = "recessive";
						it->second.gene_solved = true;
					}
				}
				else{
					recursive_fn(mymap, mymap.find(it->second.parent2));
					recursive_fn(mymap, it);
				}
			}
			else{
				recursive_fn(mymap, mymap.find(it->second.parent1));
				recursive_fn(mymap, it);
			}
		}
		else recursive_fn(mymap, ++it);
	}
	else
		return;
}
int main()
{
	int input;
	string key, gene_or_name;
	map <string, mystruct > mymap;
	cin >> input;
	for (int i = 1; i <= input; i++){
		cin >> key >> gene_or_name;
		if (gene_or_name == "dominant" || gene_or_name == "recessive" || gene_or_name == "non-existent"){
			mymap[key].gene_type = gene_or_name;
			mymap[key].parent = true;
			mymap[key].gene_solved = true;
		}
		else{
			mymap[key].child = gene_or_name;
			if (mymap[gene_or_name].parent_entered == true) { mymap[gene_or_name].parent2 = key; }
			else {
				mymap[gene_or_name].parent_entered = true;
				mymap[gene_or_name].parent1 = key;
			}
		}
	}
	map<string, mystruct>::iterator it = mymap.begin();
	while (it != mymap.end()){ recursive_fn(mymap, it); it++; }
	it = mymap.begin();
	while (it != mymap.end()){ cout << it->first << " " << it->second.gene_type << endl; it++; }
	system("pause");
	return 0;
}