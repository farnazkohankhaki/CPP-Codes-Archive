#include <iostream>
#include <algorithm>

using namespace std;

const int h[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

string s[4];

bool kh()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int x = 0;
			for (int l = 0; l < 4; l++)
				if (s[i + h[l][0]][j + h[l][1]] == '#')
					x++;
			if (x != 2)
				return true;
		}
	return false;
}
	
int main()
{
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	if (kh())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}