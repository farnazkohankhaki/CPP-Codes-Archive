#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Num {
	int k;
	int ind[2];
	
	void swap(Num x, int state) {
		swap(ind[state], x.ind[state]);
	}
	
} a[MAXN];

struct heap_num {
	int state;
	int k;
	
	heap_num() { state = 0 }
	
	bool operator < (heap_num &x) const {
		if (state)
			return a[k].k < a[x.k].k;
		return a[k].k > a[x.k].k;
	}
} harr[2][MAXN];

void myswap(heap_num x, heap_num y, int state) {
	a[x.k].swap(a[y.k], state);
	swap(x, y);	
}

int n, h[MAXN], size= 0;

void pushUp (heap_num *h, int x)
{
	while (a[x] < a[x / 2] && x > 1)
	{
		swap (a[x], a[x / 2]);
		x /= 2;
	}
}

void pushDown (heap_num *h, int x)
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

void heapify (heap_num *h)
{
	for (int i = 1; i <= n; i++)
		pushUp (h, i);
}

void remove(heap_num *h, int i) {
	myswap(h[i], h[size]);
	int ind = heap_up(h, i);
	heap_down(h , ind);
}

void add(int k) {
	size++;
	a[size].k = k;
	a[size].mini = a[size].maxi = size;
	
	harr[MIN][size].k = harr[MAX][size].k = size;
	harr[MIN][size].state = 0;
	harr[MAX][size].state = 1;
	
	push_up(harr[MIN], size);
	push_up(harr[MAX], size);
}

void remove(int state, int i) {
	remove(harr[state] , i);

	int reverse = a[harr[state][i]].ind[1-state];
	remove(harr[1-state] , reverse);
	
}

void input() {
	add(k);
	a[harr[MIN][1]].k
	a[harr[MAX][1]].k
	remove(MIN, 1);
	remove(MAX, 1);
}

int main ()
{
	input();
	return 0;
}
//by Mr.Mahini ya yeki dge