#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN];

void bubble()
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				swap (a[j], a[j + 1]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bubble();
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}