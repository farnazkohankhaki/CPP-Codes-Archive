#include <iostream>
#include <complex>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
const double eps = 1e-6;

typedef complex<int> point;

int n, tc;

point node[MAXN], convex[MAXN];

int numComp (double a, double b)
{
	if (a - b > eps)
		return 1;
	else if (a - b < -eps)
		return -1;
	else
		return 0;
}

int pointComp (point a, point b)
{
	if (numComp(real(a), real(b)))
		return numComp(real(a), real(b));
	return numComp(imag(a), imag(b));
}

int cross (const point &a, const point &b)
{
	return real(a) * imag(b) - real(b) * imag (a);
}

struct comp
{
	point o;
	comp (point oo) : o(oo)
	{}
	bool operator () (const point &a, const point &b) const
	{
		if (!cross (a - o, b - o))
			return norm (a - o) < norm (b - o);
		return (cross (a - o, b - o) > 0);
	}
};

void convexHull ()
{
	int mini = 0;
	for (int i = 1; i < n; i++)
		if (pointComp (node[i], node[mini]) < 0)
			mini = i;
	sort (node, node + n, comp (node[mini]));
	convex[0] = node[0];
	convex[1] = node[1];
	tc = 2;
	for (int i = 2; i < n; i++)
	{
		while ((tc > 1) && (cross (node[i] - convex[tc - 2], convex[tc - 1] - convex[tc - 2]) >= 0))
			tc--;
		convex[tc++] = node[i];
	}
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> real (node[i]) >> imag(node[i]);
	convexHull();
	cout << tc << endl;
	for (int i = 0; i < tc; i++)
		cout << real(convex[i]) << " " << imag (convex[i]) << endl;
	return 0;
}