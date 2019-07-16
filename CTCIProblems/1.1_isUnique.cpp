#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

bool isUniqueBrute(string s);
bool isUniqueOpt1(string s);
bool isUniqueOpt2(string s);

int main() {
	string test;
	cin >> test;

	//bool unique = isUniqueBrute(test);
	//bool unique = isUniqueOpt1(test);
	bool unique = isUniqueOpt2(test);

	if (unique)
		cout << "String contains distinct characters." << endl;
	else cout << "String does not contain distinct characters" << endl;
	return 0;
}


/*
initial brute force solution:
	compare all characters of the string to conclude whether
	there are duplicates.

	O(N^2) time, O(1) space
*/

bool isUniqueBrute(string s) {

	for(int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++){
			if (s[i] == s[j])
				return false;
		}
	}
	return true;
}

/*
Optimization #1:
	Sort the string and iterate over the contents. If one of
	the elements matches the next, then there are duplicates.

	O(NlogN) time, O(1) space
*/
bool isUniqueOpt1(string s) {
	
	sort(s.begin(), s.end());

	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == s[i + 1])
			return false;
	}
	return true;
}

/*
Optimization #2:
	Use bitset to map each character to a boolean value. 
	If a value is already true, we know there are duplicates.
	Assuming ASCII without extended values.

	O(N) time, O(1) space
*/
bool isUniqueOpt2(string s) {
	
	bitset<128> seenList;

	if(s.size() <= 128){	//cant have more than 128 unique chars in a 128 char alphabet
		for (char& c : s) {
			if (seenList[int(c)] == false)
				seenList[int(c)] = true;
			else return false;
		}
	} 
	else return true;
}