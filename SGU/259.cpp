#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100 + 8;

int t[maxN], l[maxN], w[maxN];

pair <int, int> s[maxN];

int main ()
{
	int n, tmp = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
	{
		s[i].first = -1 * l[i];
		s[i].second = t[i];
	}
	sort (s, s + n);
	for (int i = 0; i < n; i++)
	{
		w[i] = -1 * s[i].first + s[i].second + tmp;
		tmp += s[i].second;
	}
	cout << *max_element (w, w + n) << endl;
	return 0;
}