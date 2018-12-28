#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1000 + 100;

int n, arr[maxN], d[maxN], f[maxN];
vector <int> ans;

int dyna () 
{
	d[0] = 1;
	f[0] = -1;
	for (int i = 1; i < n; i++)
	{
		d[i] = 1;
		f[i] = -1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && d[i] < d[j]+1)
			{	
				d[i] = d[j]+1;
				f[i] = j;
			}
	}

	int maxi = 0;
	for (int i = 1; i < n; i++)
		if (d[i] > d[maxi])
			maxi = i;
	
	return maxi;
}

void output (int ind) 
{
	cout << d[ind] << endl;

	ans.clear ();
	while (f[ind] != -1)
	{
		ans.push_back(arr[ind]);
		ind = f[ind];
	}
	ans.push_back(arr[ind]);
	
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << endl;
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int maxi = dyna();
	output(maxi);

	return 0;
}