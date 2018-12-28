#include <iostream>

using namespace std;

const int MAXN = 100 + 10, l[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int n;
string s[MAXN];

void output()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int x = i + l[k][0], y = j + l[k][1];
				if (x == -1 || x == n || y == -1 || y == -1)
					continue;
				if (s[x][y] == 'o')
					cnt++;
			}
			if (cnt % 2)
			{
				cout << "NO" << endl;
				return;
			}
		}
	cout << "YES" << endl;
	return;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	
	output();
	
	return 0;
}