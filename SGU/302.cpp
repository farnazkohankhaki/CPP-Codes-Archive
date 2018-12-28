#include <iostream>

using namespace std;

const int maxN = 1000 + 8;

int mark[maxN] = {0};

int main ()
{
	int cnt, x;
	string s; 
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<' && mark[i] != 8)
		{
			cnt = 1;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[j] == '<' && s[j + 1] != '/')
					cnt++;
				if (s[j] == '<' && s[j + 1] == '/')
					cnt--;
				if (cnt == 0)
				{
					x = j;
					break;
				}
			}
			if (s[i + 1] == 'U')
			{
				for (int j = i; j < i + 4; j++)
					mark[j] = 8;
				for (int j = x; j < x + 5; j++)
					mark[j] = 8;
				for (int j = i + 4; j < x; j++)
					mark[j] = 1;
			}
			else
			{
				for (int j = i; j < i + 6; j++)
					mark[j] = 8;
				for (int j = x; j < x + 7; j++)
					mark[j] = 8;
				for (int j = i + 6; j < x; j++)
					mark[j] = 2;
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (mark[i] == 0)
			cout << s[i];
		if (mark[i] == 1)
			if (int (s[i]) < 97)
				cout << s[i];
			else 
				cout << char (s[i] - 32);
		if (mark[i] == 2)
			if (int (s[i]) > 96)
				cout << s[i];
			else 
				cout << char (s[i] + 32);
	}
	cout << endl;
	return 0;
}