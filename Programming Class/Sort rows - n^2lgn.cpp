#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1000 + 100;

int n;

struct satr 
{
	int a[maxN];
	
	void read ()
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void write ()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	bool operator < (const satr &x) const
	{
		for (int l = 0; l < n; l++)
		{
			if (a[l] < x.a[l])
				return 1;
			if (a[l] > x.a[l])
				return 0;
		}
		return 0;
	}
} s[maxN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		s[i].read();
	sort (s, s + n);
	for (int i = 0; i < n; i++)
		s[i].write();
	return 0;
}