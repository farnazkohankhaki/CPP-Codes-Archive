#include <iostream>

using namespace std;

string s;

int main ()
{
	cin >> s;
	
	if (s[0] - 'A' >= 32)
		s[0] = s[0] - 32;
	
	cout << s << endl;
	
	return 0;
}