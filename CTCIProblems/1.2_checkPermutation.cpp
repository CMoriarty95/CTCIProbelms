#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPermutaion(string s1, string s2);
bool ispermutationOpt1(string s1, string s2);

int main() {

	string s1, s2;

	cout << "Enter input strings:" << endl;
	cin >> s1 >> s2;

	//bool perm = isPermutaion(s1, s2);
	bool perm = ispermutationOpt1(s1, s2);

	if (perm)
		cout << "The strings are permutations." << endl;
	else cout << "The strings are not permutations." << endl;

	return 0;
}

/*
initial solution:
	First checks if strings are of equal length to ensure the possibility
	of being permutations. Then sorts both strings and checks if each index matches.

	O(NlogN) time, O(1) space
*/
bool isPermutaion(string s1, string s2) {

	if(s1.size() != s2.size())
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return equal(s1.begin(), s1.end(), s2.begin(), s2.end());

	return true;
}

/*
Optimized time complexity solution:
	First checks if strings are of equal length to ensure the possibility
	of being permutations. Then creates a vector of integers which store 
	the frequency a character appears for s1. Then iterates over s2 and decrements
	each the frequency for each character and returns false if a frequency becomes negative.

	O(N) time, O(1) space
*/
bool ispermutationOpt1(string s1, string s2) {
	
	if (s1.size() != s2.size())
		return false;

	vector<int> freq(128);

	for (char& c : s1)
		freq[c] += 1;

	for (char& c : s2){
		freq[c] -= 1;
		if (freq[c] < 0)
			return false;
	}

	return true;
}