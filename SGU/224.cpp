#include <iostream>

using namespace std;

const int maxN = 20 + 8;

bool mark1[maxN] = {0}, mark2[maxN] = {0}, mark3[maxN] = {0};
int n, k, r = 0;

void f (int q, int x)
{
	if (q == 0)
	{
		r++;
		return;
	}
	if (x == n)
		return;
	for (int i = 0; i < n; i++)
	{
		if (!mark1[i] && !mark2[x + i] && !mark3[x - i + n - 1])
		{
			mark1[i] = 1;
			mark2[x + i] = 1;
			mark3[x - i + n - 1] = 1;
			f (q - 1, x + 1);
			mark1[i] = 0;
			mark2[x + i] = 0;
			mark3[x - i + n - 1] = 0;			
		}
	}
	f (q, x + 1);

}

int main()
{
	cin >> n >> k;
	f (k, 0);
	cout << r << endl;
	return 0;
}