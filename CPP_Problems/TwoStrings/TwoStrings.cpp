#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
string twoStrings(string s1, string s2) {
	string returnString("NO");
	unordered_set<char> us_chars;
	us_chars.insert(s1.begin(), s1.end());
	for (char &eachchar : s2)
	{
		if (us_chars.find(eachchar) != us_chars.end())
		{
			returnString = "YES";
		}
	}
	return returnString;
}

int main()
{
	string color1("yellow");
	string color2("red");

	cout << twoStrings(color1, color2) << endl;
	system("pause");
	return EXIT_SUCCESS;
}