#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector <int> a, b;

int main()
{
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		if (s[i] == 'l')
			a.push_back(i + 1);
		else
			b.push_back(i + 1);
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}