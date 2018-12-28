#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000 + 100;

int n, m, a[MAXN], ind[MAXN];
pair <int, int> asort[MAXN];

int d[MAXN], p[MAXN];
vector<int> sol;

struct Node 
{
	int max, maxi;
	int s, t;
	
	void update (Node u)
	{
		max = u.max;
		maxi = u.maxi;
	}
} node[MAXN];

void input ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];		
}

int findM(int n)
{
	int r = 1;
	while (r < n)
		r *= 2;
	return r;
}

int left(int i) {
	return 2*i+1;
}
int right(int i) {
	return 2*i+2;
}
int getArrayInd(int ind) {	// TreeInd -> ArrayInd
	return ind-m+1;
}
int getTreeInd(int ind) {
	return m+ind-1;
}
int par(int i) {
	return (i-1)/2;
}


void initTree (int i, int s, int t)	// [s,t)
{
//	cerr << "[" << i << "," << s << "," << t << ")" << endl;
	node[i].s = s;
	node[i].t = t;
	node[i].max = 0;
	node[i].maxi = -1;
	
	if (i >= m-1)
		return;
	
	initTree (left(i), s, (s+t)/2);
	initTree (right(i), (s+t)/2, t);
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		asort[i].first = a[i];
		asort[i].second = i;
	}
	sort (asort, asort + n);
	for (int i = 0; i < n; i++)
		ind[asort[i].second] = i;
	
	m = findM (n);
	initTree (0, 0, m);
}

void update(int arrayInd, int len) {
	int ind = getTreeInd(arrayInd);
	node[ind].max = len;
	node[ind].maxi = ind;
	
	for (int i= ind; i > 0 && node[par(i)].max < node[i].max; i = par(i))
		node[par(i)].update(node[i]);
}

int mymax(int x , int y) {
	if (x == -1)
		return y;
	if (y == -1)
		return x;
	return (node[x].max > node[y].max) ? x : y;
}

int findMax(int r, int i) {	// [0,i)
//	cerr << "[" << r << "," << i << "] - [" << node[r].s << "," << node[r].t << "]" << endl;
	if (i >= node[r].t)
		return node[r].maxi;
	if (i < node[r].s)
		return -1;
	if (r >= m-1)
		return node[r].maxi;
	return mymax(findMax(left(r), i), findMax(right(r), i));
}

void LIS ()
{
	for (int i = 0; i < n; i++)
	{
		int arrayInd = ind[i];
		int maxInd = findMax (0 , arrayInd);
		
		if (maxInd != -1) {
			d[i] = node[maxInd].max + 1;
			p[i] = asort[getArrayInd(maxInd)].second;
		} else {
			d[i] = 1;
			p[i] = -1;
		}
		update(arrayInd, d[i]);
	}
}
		
void output() {
	int maxi = 0;
	for (int i= 1; i < n; i++)
		if (d[i] > d[maxi])
			maxi = i;	
	cout << d[maxi] << endl;
	while (maxi != -1) {
		sol.push_back(maxi);
		maxi = p[maxi];
	}
	for (int i= sol.size()-1; i >= 0; i--)
		cout << a[sol[i]] << " ";
	cout << endl;
}

int main ()
{
	input ();
	init ();
	LIS();
	output();
	return 0;
}
//by Mr. Mahini
