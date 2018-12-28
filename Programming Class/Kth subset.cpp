#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20 + 10;

int n = 20, r = 10, k, d[MAXN][MAXN];

vector <int> sol;

void dyna()
{
	for (int i = 0; i <= n; i++)
		d[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
}

void mSolve() 
{
	for (int i= 1; i <= 20; i++) 
	{
		if (k < d[n-i][r-1]) 
		{
			sol.push_back(i);
			r--;
		} else
			k -= d[n-i][r-1];

		if (r == 0)
			break;
	}
}
	
int main()
{
	cin >> k;
	dyna();
	k--;
	mSolve();
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i] << " ";
	cout << endl;
	return 0;
}