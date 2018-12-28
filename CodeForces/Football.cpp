#include <iostream>

using namespace std;

string s;

int main()
{
	cin >> s;

	int state = -1, cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			if (state == 0)
				cnt0++;
			else
			{
				state = 0;
				cnt0 = 1;
				cnt1 = 0;
			}
		}
		else
		{
			if (state == 1)
				cnt1++;
			else
			{
				state = 1;
				cnt1 = 1;
				cnt0 = 0;
			}
		}
		if (cnt1 == 7 || cnt0 == 7)
		{
			state = -1;
			cout << "YES" << endl;
			break;
		}
	}
	if (state != -1)
		cout << "NO" << endl;
	
	return 0;
}