#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1000*1000 + 100;
int n;
int a[MAXN], d[MAXN];
map<int,int> list;

int main() {
	cin >> n;
	for (int i= 0; i < n; i++)
		cin >> a[i];
	
	for (int i= 0; i < n; i++) {
		int x = a[i];
		map<int,int>::iterator p = list.lower_bound(x);
		if (p != list.begin()) {
			p--;
			d[i] = p->second + 1;
		} else
			d[i] = 1;
	
		while (true) {
			map<int,int>::iterator p = list.upper_bound(x);
			if (p != list.end() && p->second < d[i])
				list.erase(p);
			else
				break;
		}
		list[a[i]] = d[i];
	}
	cout << *max_element(d,d+n) << endl;
	return 0;
}
//by Mr. Mahini