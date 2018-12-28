#include <iostream>
#include <vector>

using namespace std;

int n, h;

vector <int> r, l, ans;

void makeR ()
{
	long long p = h * h;
	for (int i = 1; p <= n; i++)
	{
		r.push_back (p);
		p = (h + i) * (h + i) - i;
	}
}

void makeL ()
{
	long long p = h * h + h;
	for (int i = 1; p <= n; i++)
	{
		l.push_back (p);
		p = (h + i) * (h + i) + h;
	}
}
	
		
		
void makeH ()
{
	makeR();
	makeL();
	for (int i = l.size() - 1; i >= 0; i--)
		ans.push_back(l[i]);
	for (int i = 0; i < r.size(); i++)
		ans.push_back(r[i]);
}

int main ()
{
	cin >> n >> h;
	h++;
	makeH();
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}