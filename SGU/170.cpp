#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	string a, b;
	int ans = 0;
	bool f = 1;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			for (int j = i + 1; j < a.size(); j++)
				if (b[j] == a[i])
				{
					ans += j - i;
					b[j] = b[i];
					b[i] = a[i];
					break;
				}
	for (int i = 0; i < max (a.size(), b.size()); i++)
		if (a[i] != b[i])
			f = 0;
	if (f)
		cout << ans << endl;
	else
		cout << -1 << endl;
}