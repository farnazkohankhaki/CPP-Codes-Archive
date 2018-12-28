#include <iostream>

using namespace std;

int n;

int main ()
{
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}
	
	if (sum % n == 0)
		cout << n << endl;
	else 
		cout << n - 1 << endl;
	
	return 0;
}