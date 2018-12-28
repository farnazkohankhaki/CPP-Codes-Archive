#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

int a[MAXN], tmp[MAXN];

void merge (int s, int t, int mid)
{
	int p1 = s, p2 = mid, cnt = s;
	
	while (p1 < mid && p2 < t)
		if (a[p1] <= a[p2])
		{
			tmp[cnt] = a[p1];
			p1++;
			cnt++;
		}
		else 
		{
			tmp[cnt] = a[p2];
			p2++;
			cnt++;
		}
	if (p2 == t)
		for (int i = cnt; i < t; i++)
			a[i] = a[i - t + mid];
	for (int i = s; i < cnt; i++)
		a[i] = tmp[i];
    
    return;
}

void sort (int s, int t)
{
	if (t - s < 2)
		return;
    
	int mid = (s + t) / 2;
	sort (s, mid);
	sort (mid, t);
	merge (s, t, mid);
    
    return;
}

int main () 
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
    
	sort (0, n);
	
    for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
    
	return 0;
}