#include<iostream>
#include <vector>
using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
	vector<int> rotarray;
	int arraySize = a.size();

	for (int arrayitr(0); arrayitr < a.size(); arrayitr++)
	{
		int itr = (arrayitr + d) % arraySize;
		rotarray.push_back(a[itr]);
	}
	return rotarray;
}

void printArray(vector<int> data)
{
	for (auto & eachdata : data)
	{
		cout << eachdata << "\t";
	}
	cout << endl;
}

int main()
{
	vector<int> data{ 1,2,3,4,5 };
	int rotationfactor = 4;
	cout << "actual array : " << endl;
	printArray(data);

	cout << "After left rotation by factor " << rotationfactor << endl;
	printArray(rotLeft(data, rotationfactor));
	system("pause");
	return EXIT_SUCCESS;
}