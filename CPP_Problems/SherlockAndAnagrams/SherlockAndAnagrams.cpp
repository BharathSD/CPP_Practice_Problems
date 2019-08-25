#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int sherlockAndAnagrams(string s) {
	// hashTable
	unordered_map<string, int> um_hashTable;
	int strLen(s.size());
	for (int i(0); i < strLen; ++i)
	{
		for (int l = 1; l <= strLen - i; ++l)
		{
			string substr = s.substr(i, l);
			sort(substr.begin(), substr.end());
			um_hashTable[substr]++;
		}
	}
	int noOfAnagrams(0);
	for (unordered_map<string, int>::iterator it = um_hashTable.begin();
		it != um_hashTable.end(); ++it)
	{
		int & val = it->second;
		noOfAnagrams += val * (val - 1) / 2;
	}
	return noOfAnagrams;
}

int main()
{
	string data("abbc");
	cout << "no of Anagrams in substrings of string \"" << data << "\" are : " << sherlockAndAnagrams(data) << endl;
	system("pause");
	return EXIT_SUCCESS;
}