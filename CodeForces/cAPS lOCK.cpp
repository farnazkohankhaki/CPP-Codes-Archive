#include <iostream>

using namespace std;

string s;

int main ()
{
	cin >> s;
	
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < s.size(); i++)

		if (s[i] - 'A' < 32)
			cnt1++;
		else
			cnt2++;
	if (cnt2 == 0 || cnt2 == 1 && (s[0] - 'A') >= 32)
	{
		for (int i = 0; i < s.size(); i++)
			if (s[i] - 'A' < 32)
				s[i] = s[i] + 32;
			else
				s[i] = s[i] - 32;
	}
	
	cout << s << endl;
	
	return 0;
}