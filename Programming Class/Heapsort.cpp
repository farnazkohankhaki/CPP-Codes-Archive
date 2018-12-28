#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN], h[MAXN], size;

void pushUp (int x)
{
	while (a[x] < a[x / 2] && x > 1)
	{
		swap (a[x], a[x / 2]);
		x /= 2;
	}
}

void pushDown (int x)
{
	for (bool flag = true; 2 * x <= size && flag; ) 
	{
		int w = 0, mini = 2 * x, oth = 2 * x + 1;
		if (oth <= size && a[oth] < a[mini])
		{
			w = 1;
			mini = oth;
		}
		if (a[mini] < a[x])
		{
			swap (a[x], a[mini]);
			x = 2 * x + w;
		}
		else
			flag = false;
	}
}

void deleteMin ()
{
	a[1] = a[size];
	pushDown (1);
	size--;
}

void heapify ()
{
	for (int i = 1; i <= n; i++)
		pushUp (i);
}

void heapsort ()
{
	for (int i = 0; i < n; i++)
	{
		h[i] = a[1];
		deleteMin();
	}
}

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	size = n;
	heapify();
	heapsort();
	for (int i = 0; i < n; i++)
		cout << h[i] << " ";
	cout << endl;
	return 0;
}