// be name khoda

#include <iostream>

using namespace std;

const int MAXN = 10 + 10;
const int MAXK = (1<<10) + 1000;
const int halN = 4;
// const int h[10][2] = {{0,0},{0,1},{1,0},{1,1},{1,1},{3,1},{1,3},{3,0},{0,3},{3,3}};
const int h[halN][2] = {{0,0},{1,0},{1,1},{3,0}};

int n, m;
int a[MAXN][MAXN], num[MAXN], numd[MAXN];
int d[MAXN][MAXK][MAXK];
int ans[MAXN][MAXK];

void input() {
	cin >> n >> m;
	for (int i= 0; i < n; i++) {
		for (int j= 0; j < m; j++) {
			cin >> a[i][j];
			num[i] = (num[i]<<1) + a[i][j];
		}
		numd[i] = ((1<<m)-1)^num[i];
	}
}

void init() {
	d[1][0][0] = 1;
	d[1][1][0] = 1;
	d[1][1][1] = 1;

	for (int k= 2; k <= m; k++) {
	//	cerr << "======= " << k << " =======" << endl;
		for (int p= 0; p < (1<<k); p++)
			for (int q= 0; q < (1<<k); q++) {
				for (int i= 0; i < halN; i++) {
					int a= h[i][0] , b= h[i][1];
					int pcheck = p&2, qcheck = q&2;
					int pn= p^a, qn= q^b;
					if (pn%2 == 0 && qn%2 == 0 && pcheck >= (a&2) && qcheck >= (b&2)) {
	//					cerr << "(" << a << "," << b << ")" << endl;
						d[k][p][q] += d[k-1][pn>>1][qn>>1];
					}
				}
	//			cerr << "(" << k << "," << p << "," << q << "): " << d[k][p][q] << endl;
			}
	}
}

void solve() {
//	cerr << "===== init =====" << endl;
	for (int p= 0; p < (1<<m); p++)
		if ((num[0]&p) == 0) {
			ans[0][p] = d[m][p][0];
//			cerr << p << " " << d[m][p][0] << endl;
		}

//	cerr << "============" << endl;
	for (int i= 1; i <= n; i++)
		for (int p= 0; p < (1<<m); p++) {
			for (int q= 0; q < (1<<m); q++)
				if ((num[i-1]&q) == 0) {
					int t = (1<<m)-1;
		//			cerr << q << "-" << (t^(q|num[i-1])) << endl;
					ans[i][p] += d[m][p][q]*ans[i-1][t^(q|num[i-1])];
		//			cerr << ans[i-1][t^(q|num[i-1])] << " " << ans[i][p] << endl;
				}
		//	cerr << "(" << i << "," << p << "): " << ans[i][p] << endl;
		}
}

int main() {
	input();
	init();
	solve();
	cout << ans[n][0] << endl;
	return 0;
}
