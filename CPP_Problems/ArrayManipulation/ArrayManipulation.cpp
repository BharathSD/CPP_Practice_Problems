#include<iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries)
{
	long maxValue = LONG_MIN;
	vector<long> v_array(n + 1, 0);
	// it is assumed that size of each query is 3
	for (auto &query : queries)
	{
		auto startIdx = query[0];
		auto endIdx = query[1];
		auto val = query[2];
		v_array[startIdx] += val;
		if ((endIdx + 1) <= n)
		{
			v_array[endIdx + 1] -= val;
		}
	}
	long sum(0);
	for (auto & data : v_array)
	{
		sum += data;

		if (maxValue < sum)
		{
			maxValue = sum;
		}
	}
	return maxValue;
}

int main()
{
	vector<vector<int>> v_queries{ 
									{1, 2, 100},
									{2, 5, 100},
									{3, 4, 100},
								 };
	int arrayLength = 5;
	cout << "Maximum value in a array : " << arrayManipulation(arrayLength, v_queries) << endl;
	system("pause");
	return EXIT_SUCCESS;
}