#include <iostream>

using namespace std;

const int maxN = 10000 + 100;

bool mark[maxN];
int n, a[maxN], p[maxN];
long long sum, r;


int main ()
{
	double tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += (double) a[i];
	}
	for (int i = 0; i < n; i++)
	{
		
		p[i] = a[i] * 100 / sum;
		r += p[i];
		tmp = (double)a[i] / (double) sum;
		if ((double)p[i] - tmp == 0)
			mark[i] = 1;
	}
	for (int i = 0; i < n && r < 100; i++)
		if (!mark[i])
		{
			p[i]++;
			r++;
		}
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}