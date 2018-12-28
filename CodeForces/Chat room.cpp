#include <iostream>

using namespace std;

const string ans = "hello";

string s;

bool isHello()
{
	int p = 0;
	
	for (int i = 0; i < 5; i++)
		for (p; p < s.size(); p++)
			if (ans[i] == s[p])
			{
				if (i == 4)
					return true;
				p++;
				break;
			}
	
	return false;
}

int main ()
{
	cin >> s;
	
	if (isHello())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}