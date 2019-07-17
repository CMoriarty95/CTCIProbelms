#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool palPerm(string s);

int main() {

	string s;
	bool isPerm;

	cout << "Enter string: " << endl;
	getline(cin, s);

	isPerm = palPerm(s);

	if (isPerm)
		cout << "String is a permutation of a palindrome." << endl;
	else cout << "String is NOT a permutation of a palindrome." << endl;

	return 0;
}

/*
initial solution:
	given that a palindrome must read the same forwards as it does backwards,
	i observed a couple things:
		1) if the palindrome has an even number of characters, each character must have
		an identicle counterpart
		2) if the palindrome is odd numbered, there must be only one character without a
		counterpart
	using these facts, I wrote the following code. Initially, assuming ASCII values, each 
	character is mapped to its corresponding index in a bitset. Then by iterating through
	the bitset, the number of true values are recorded in count (true values correspond to
	odd numbered character frequencies). then finally, depending on the length of the string,
	odd or even, the correct value is returned.

	O(N) time, O(1) space
*/
bool palPerm(string s) {
	
	bitset<128> b;	//assuming ASCII
	int count = 0;

	for (char& c : s) {
		if (b[int(c)])
			b[int(c)] = false;
		else b[int(c)] = true;
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i])
			count++;
	}

	if (s.size() % 2 == 0 && count == 0)
		return true;
	else if (s.size() % 2 == 1 && count == 1)
		return true;
	else return false;
}