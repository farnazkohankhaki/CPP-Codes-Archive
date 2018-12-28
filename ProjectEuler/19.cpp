#include <iostream>

using namespace std;

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ml[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap (int x)
{
	if (x % 100 == 0)
	{	
		if (x % 400 == 0)
			return 1;
		return 0;
	}
	if (x % 4 != 0)
		return 0;
	return 1;
}

int main ()
{
	int p = (31 * 7 + 30 * 4 + 28 + 1) % 7, ans = 0;
	for (int i = 1901; i < 2001; i++)
	{
		if (!isleap (i))
			for (int j= 0; j < 12; j++)
			{
				if (p == 0)
					ans++;
				p = (p + m[j]) % 7;
			}
		else
			for (int j= 0; j < 12; j++)
			{
				if (p == 0)
					ans++;
				p = (p + ml[j]) % 7;
			}		
	}
	cout << ans << endl;
}