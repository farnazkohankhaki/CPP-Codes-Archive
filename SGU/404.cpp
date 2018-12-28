#include <iostream>

using namespace std;

const int maxN = 100 + 8;

string a[maxN];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	cout << a[(n - 1) % m] << endl;
	return 0;
}