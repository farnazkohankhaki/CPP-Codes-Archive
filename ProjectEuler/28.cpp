#include <iostream>

using namespace std;

int main()
{
	int sum = 1;
	for (int i = 3; i <= 1001; i += 2)
		for (int j = (i - 2) * (i - 2) + (i - 1); j <= i * i; j += (i - 1))
			sum += j;
	cout << sum << endl;
	return 0;
}