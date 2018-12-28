#include <iostream>
#include <algorithm>

using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
	int cnt = 1;
	while (cnt != 1000000)
	{
		int tmp = next_permutation (a, a + 10);
		cnt++;
	}
	for (int i = 0; i <= 9; i++)
		cout << a[i];
	cout << endl;
	return 0;
}