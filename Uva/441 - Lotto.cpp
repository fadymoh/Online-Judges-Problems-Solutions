#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int k, x;
	cin >> k;
	while (k != 0)
	{
		vector <int> myvector;
		for (int i = 0; i < k; i++){
			cin >> x;
			myvector.push_back(x);
		}
		sort(myvector.begin(), myvector.end());
		for (int i = 0; i < myvector.size(); i++)
			for (int j = i + 1; j < myvector.size(); j++)
				for (int k = j + 1; k < myvector.size(); k++)
					for (int q = k + 1; q < myvector.size(); q++)
						for (int w = q + 1; w < myvector.size(); w++)
							for (int h = w + 1; h < myvector.size(); h++)
								cout << myvector[i] << " " << myvector[j] << " " << myvector[k] << " " << myvector[q] << " " << myvector[w] << " " << myvector[h] << endl;
				
							cin >> k;
							if (k) cout << endl;
	}




	system("pause");
	return 0;
}