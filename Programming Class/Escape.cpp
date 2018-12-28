#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
const char dirc[4] = {'D','U','R','L'};

int n, m, fix, fiy, mark[maxN][maxN], di[maxN][maxN];
string s[maxN];
vector <int> ansx, ansy;
bool isFinished;

void input()
{
	cin >> n >> m;
	getline(cin, s[0]);
	for (int i = 0; i < n + 2; i++)
		getline(cin, s[i]);
}


bool isExit(int x , int y) {
	if (x != 0 && x != n+1 && y != 0 && y != m+1)
		return false;
	
	if (s[x][y] == ' ')
		return true;
	
	return false;
}

bool isEmpty(int x, int y) {
	if (x == 0 || x == n+1 || y == 0 || y == m+1)
		return false;
	if (s[x][y] == '*')
		return false;
	return true;
}

bool dfs (int x, int y)
{
	mark[x][y] = 1;
	
	for (int i= 0; i < 4; i++) {
		int tmx = x + dir[i][0], tmy = y + dir[i][1];
		if (isExit(tmx, tmy)) {
			di[tmx][tmy] = i;
			fix = tmx;
			fiy = tmy;
			return true;
		}
		if (isEmpty(tmx, tmy) && !mark[tmx][tmy]) {
			di[tmx][tmy] = i;
			if (dfs(tmx, tmy))
				return true;
		}
	}
	
	return false;
}

void output()
{
	if (!isFinished)
	{
		cout << ":|" << endl;
		return;
	}
	while (s[fix][fiy] != '#')
	{
		ansx.push_back(fix);
		ansy.push_back(fiy);

		int d = di[fix][fiy];
		fix = fix - dir[d][0];
		fiy = fiy - dir[d][1];
	}
	for (int i = ansx.size() - 1; i >= 0; i--) {
		int tmx = ansx[i] , tmy = ansy[i];
		cout << dirc[di[tmx][tmy]] <<": " << tmx << ", " << tmy << endl;
	}
}

int main ()
{
	input();
	int stx, sty;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '#')
			{
				stx = i;
				sty = j;
				break;
			}
	isFinished = dfs(stx, sty);
	output();
	return 0;
}