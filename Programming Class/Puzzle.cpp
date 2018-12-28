#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 10, MAXP = 100000000 + 10;

bool mark[MAXP];
int a[MAXN], n = 9, par[MAXP], b[9], h[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, dis[MAXP];
queue <int> q;

void input() 
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int getNum (int aa[])
{
	int t[MAXN], f[MAXN];
	int ans = 1;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		t[i] = i - 1;
		f[i] = f[i - 1] * i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			if (aa[j] < aa[i])
				t[aa[i]]--;
		ans += t[aa[i]] * f[n - i - 1];
	}
	return ans;
}

void getPerm (int num)
{
	int f[MAXN], mark[MAXN];
	num--;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * i;
		mark[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int x = num / f[n - i - 1], sum = 0, j;
		for (j = 1; sum <= x; j++)
			sum += mark[j];
		j--;
		mark[j] = 0;
		b[i] = j;
		num -= f[n - i - 1] * x;
	}
}

int findEmptyCell (int a[])
{
	for (int i = 0; i < n; i++)
		if (a[i] == 9)
			return i;
}

bool isCell (int x, int y)
{
	if (x > 2 || x < 0 || y > 2 || y < 0)
		return false;
	return true;
}

void push(int x, int y) 
{  // x -> y
	if (mark[y])
		return;
	
	mark[y] = true;
	par[y] = x;
	q.push(y);
	
	if (x != -1)
		dis[y] = dis[x] + 1;
}

bool move(int a[], int b[], int k) 
{ // return true if movement is ok
	int ind = findEmptyCell(a);
	int x = ind/3, y = ind%3;
	int xp = x + h[k][0] , yp = y + h[k][1];
    
	if (!isCell(xp, yp))
		return false;
	
	int newInd = 3*x+y;
	
	for (int i= 0; i < n; i++) // initial new permutation
		b[i] = a[i];
	swap(b[ind], b[newInd]);   // do movement.
	
	return true;
}

void update(int x) 
{
	int c[9];
	getPerm(x);
    
	for (int i= 0; i < 4; i++)
		if (move(b, c, i)) {
			int y = getNum(c);
			push(x, y);
		}
}

bool isFinish(int x) 
{
	return (x == 0); // jaygasht hamani
}

void bfs() 
{
	int st = getNum(a);
	push(-1, st);
    
	while(!q.empty()) {
		int x= q.front();
		q.pop();
		update(x);
		
		if (isFinish(x))
			break;
	}
	
}

void find() 
{
	bfs();
}

void write (int x)
{
	cout << x << endl;
}

void output() 
{
	int x = getNum(a);
	while (!isFinish(x)) {
		write(x);
		x = par[x];
	}
}

int main() 
{
	input();
	find();
	output();
	return 0;
}
//nemidunam doroste ya na, hesse chek nabud, tu folder N e tu desktop bud yadam nemiumad chie