#include <iostream>

using namespace std;

const int maxN = 100 + 8;

int a[maxN][maxN] = {{0}};
int n, k;

void f (int k, int n)
{
	for (int i = 0; i <= n; i++)
		a[i][0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
}

int main ()
{
	cin >> n >> k;
	f(k, n);
	cout << a[n][k] << endl;
	return 0;
}