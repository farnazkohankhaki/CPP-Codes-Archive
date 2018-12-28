#include <iostream>

using namespace std;

const int MAXN = 100 + 10;
const int stat[5][5] = {{0,0}, {1, -1}, {1, 0}, {1, 1}, {2, 0}};

int n;
string s[MAXN];
bool b[MAXN][MAXN];

bool can()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[i][j])
				for (int k = 0; k < 5; k++)
				{
					int x = i + stat[k][0], y = j + stat[k][1];
					if (x < 0 || y < 0 || y == n || x == n)
						return false;
					if (!b[x][y])
						return false;
					b[x][y] = false;
				}
	
	return true;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '#')
				b[i][j] = true;
	
	if (can())
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	
	return 0;
}