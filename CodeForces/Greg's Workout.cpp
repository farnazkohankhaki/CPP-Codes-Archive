#include <iostream>
#include <algorithm>

using namespace std;

int n, a[3];
string s[3] = {"chest", "biceps", "back"};

int main ()
{
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;	
		a[i % 3] += x;
	}
	int p = max_element (a, a + 3) - a;
	cout << s[p] << endl;
	return 0;
}