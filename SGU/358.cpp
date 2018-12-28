#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[3][3], b[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	for (int i = 0; i < 3; i++)
	{
		sort (a[i], a[i] + 3);
		b[i] = a[i][1];
	}
	sort (b, b + 3);
	cout << b[1] << endl;
	return 0;
}