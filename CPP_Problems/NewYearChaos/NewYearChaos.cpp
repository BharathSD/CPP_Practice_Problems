#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minimumBribes(vector<int> q) {

	// iterate over the vector
	int moves(0);
	bool isChaotic(false);
	for (int pos(0); pos < q.size(); ++pos)
	{
		int val(q[pos]);
		if (((val - 1) - pos) > 2)
		{
			isChaotic = true;
			break;
		}
		for (int itr = std::max(0, val - 2); itr < pos; ++itr)
		{
			if (q[itr] > val)
			{
				moves++;
			}
		}
	}
	if (isChaotic)
	{
		cout << "Too chaotic" << endl;
	}
	else
	{
		cout << moves << endl;
	}
}

int main()
{
	vector<int> data{ 2, 1, 5, 3, 4 };
	minimumBribes(data);
	system("pause");
	return EXIT_SUCCESS;
}