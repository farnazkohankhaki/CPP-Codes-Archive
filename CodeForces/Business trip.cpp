#include <iostream>
#include <algorithm>

using namespace std;

int x, a[12];

int ans ()
{
	if (x == 0)
		return 0;
	
	sort (a, a + 12);
	
	int sum = 0;
	for (int i = 11; i >= 0; i--)
	{
		sum += a[i];
		if (sum >= x)
			return 12 - i;
	}

	return -1;
}

int main ()
{
	cin >> x;
	for (int i = 0; i < 12; i++)
		cin >> a[i];
	
	cout << ans() << endl;
	
	return 0;
}