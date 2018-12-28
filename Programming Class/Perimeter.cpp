#include <iostream>
#include <set>

#define mp make_pair

using namespace std;

const int h[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, x, y;
int r= 3;
set <pair <int, int> > s;

int move(int x, int y, int d) {
	int t = 0;	
	
	d = (d+2)%4;
	
	for (int i = 1; i <= 4; i++)
	{
		d = (d+1)%4;
		int xn = x + h[d][0] , yn = y + h[d][1];
		if (s.find(mp(xn, yn)) != s.end())
			return i;
	}
	return -1;
}

int findAns()
{
	int sx, sy;
	pair <int, int> p = *s.begin();
	sx = x = p.first;
	sy = y = p.second;
	if (s.find(mp(x+1, y)) != s.end())
		r--;
	if (s.find(mp(x, y+1)) != s.end())
	if (r == 3)
		return 4;
	int d = 1;
	bool start = false;
	int flag = 0;
	while (true)
	{
		flag++;
		int cnt = move(x, y, d);
		int dnew = (d+2+cnt)%4;
		if (x == sx && y == sy && dnew == 0 && start)
			break;
		
		start = true;
		r += (cnt-1);
		d = dnew;
		
		x += h[d][0];
		y += h[d][1];
	}
	
	return r;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		s.insert(mp(x, y));
	}
	cout << findAns() << endl;
	return 0;
}