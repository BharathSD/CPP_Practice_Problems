#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumSwaps(vector<int> arr) 
{
	int swapcount(0);
	vector<pair<int, int>> v_dataIndexpair(arr.size());

	for (size_t itr(0); itr < arr.size(); ++itr)
	{
		v_dataIndexpair[itr].first = arr[itr];
		v_dataIndexpair[itr].second = itr;
	}

	sort(v_dataIndexpair.begin(), v_dataIndexpair.end());

	for (size_t itr(0); itr < arr.size(); ++itr)
	{
		// if same index is present
		if (v_dataIndexpair[itr].second != itr)
		{
			v_dataIndexpair[itr].swap(v_dataIndexpair[v_dataIndexpair[itr].second]);

			if (v_dataIndexpair[itr].second != itr)
			{
				itr--;
			}
			swapcount++;
		}
	}
	return swapcount;
}

int main()
{
	vector<int> data{ 7, 1, 3, 2, 4, 5, 6 };
	cout << "Minimum swaps needed : " << minimumSwaps(data) << endl;
	system("pause");
	return EXIT_SUCCESS;
}