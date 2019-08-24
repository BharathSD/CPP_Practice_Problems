#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void checkMagazine(vector<string> magazine, vector<string> note)
{
	string printstring("Yes");
	unordered_map<string, int> um_magazine;
	for (auto&eachstr : magazine)
	{
		um_magazine[eachstr]++;
	}

	for (auto&eachNoteStr : note)
	{
		if (um_magazine.find(eachNoteStr) == um_magazine.end())
		{
			printstring = "No";
			break;
		}
		else
		{
			um_magazine[eachNoteStr]--;
			if (um_magazine[eachNoteStr] < 0)
			{
				printstring = "No";
				break;
			}
		}
	}
	cout << printstring << endl;
}

int main()
{
	vector<string> v_magazine{ "give", "me", "one", "grand", "today", "night"	};
	vector<string> v_note{ "give", "one", "grand", "today"};
	checkMagazine(v_magazine, v_note);
	system("pause");
	return EXIT_SUCCESS;
}