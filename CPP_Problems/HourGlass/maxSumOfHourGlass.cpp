#include <iostream>
#include <vector>
using namespace std;

int hourglassSum(vector<vector<int>> arr) 
{
	int nRows(arr.size());
	int nCols(arr[0].size());
	int retVal;
	// min size needed for hour glass is 3 rows and 3 cols
	if ((nRows < 3) || (nCols < 3))
	{
		retVal = -1;
	}
	else
	{
		retVal = INT_MIN;
		for (int rowitr(0); rowitr < nRows - 2; ++rowitr)
		{
			for (int colitr(0); colitr < nCols - 2; ++colitr)
			{
				int val = arr[rowitr][colitr] + arr[rowitr][colitr + 1] +
					arr[rowitr][colitr + 2] + arr[rowitr + 1][colitr + 1] + arr[rowitr + 2][colitr] +
					arr[rowitr + 2][colitr + 1] + arr[rowitr + 2][colitr + 2];

				if (val > retVal)
				{
					retVal = val;
				}
			}
		}
	}
	return retVal;
}

int main()
{
	vector<vector<int>> data{ {-9, -9, -9,  1, 1, 1},
								{ 0, -9,  0,  4, 3, 2},
								{ -9, -9, -9,  1, 2, 3},
								{ 0,  0,  8,  6, 6, 0},
								{ 0,  0,  0, -2, 0, 0},
								{ 0,  0,  1,  2, 4, 0 }
							};
	cout << "Maximum sum of the hour glass : " << hourglassSum(data) << endl;
	system("pause");
	return EXIT_SUCCESS;
}