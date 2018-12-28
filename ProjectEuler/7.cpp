#include <iostream>

using namespace std;

const int maxN = 1000000 + 8;

bool mark[maxN] = {0};

void prime (int n)
{
	int count = 0, move = 2;
	while (count != n)
	{
		if (!mark[move])
		{
			for (int i = move; i <= 1000000 / move; i++)
				mark[i * move] = 1;
			count++;
		}
		move++;
	}
	cout << move - 1 << endl;
}
		
int main()
{
	int n;
	cin >> n;
	prime (n);
	return 0;
}