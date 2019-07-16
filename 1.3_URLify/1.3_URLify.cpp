#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void URLify(string& s);

int main() {
	string s;
	cout << "Input string to URLify:" << endl;
	getline(cin, s);

	URLify(s);

	cout << s << endl;

	return 0;
}

/*
initial solution:
	uses the string::replace() combined with string::find() to locate
	all whitespace and replace it with %20.

	O(N) time, O(1) space
*/
void URLify(string& s) {
	
	string old = " ";
	int pos;

	while ((pos = s.find(old)) != string::npos)
		s.replace(pos, old.length(), "%20");
}