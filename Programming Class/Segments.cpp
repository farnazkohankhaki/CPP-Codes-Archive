#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 10000 + 1000;

struct interval
{
	int s, f, ind;
	bool operator < (const interval &x) const
	{
		return (s < x.s);
	}
} b[MAXN];

int n, x;
multiset < pair < int, int> > s;
vector <int> seglist, ans;
int anscolor = MAXN;

void input()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i].s >> b[i].f;
		b[i].ind = i;
	}
}

void updateans(int k) {
	if (k >= anscolor)
		return ;
	
	anscolor = k;
	ans.clear();
	for (int i= 0; i < seglist.size(); i++)
		ans.push_back(seglist[i]);
}

void clear (int x)
{
	while (!s.empty())
	{
		int p = s.begin()->first;
		if (p < x)
		{
			seglist.push_back(s.begin()->second);
			s.erase(s.begin());
		}
		else
			break;
	}
}

int maxSeg (int k)
{
	int cnt = 0;
	s.clear();
	seglist.clear();
	
	for (int i = 0; i < n; i++)
	{
		interval seg = b[i];
		clear (seg.s);
		if (s.size() < k)
		{
			cnt++;
			s.insert(make_pair(seg.f, seg.ind));
		}
		else
		{
			multiset < pair <int, int> >::iterator it = s.end();
			it--;
			if (it->first > seg.f)
			{
				s.erase(it); 
				s.insert(make_pair(seg.f, seg.ind));
			}
		}
	}
	while(!s.empty())
	{
		seglist.push_back(s.begin()->second);
		s.erase(s.begin());
	}
	
	if (cnt >= x) {
		updateans(k);
	}
	
	return cnt;
}
		
int bSearch (int s, int f)	// [s,f)
{
	if (s + 1 == f)
	{
		if (maxSeg(s) < x)
			return n+1;
		return s;
	}
	int mid = (s + f) / 2;
	if (maxSeg(mid) < x)
		return bSearch(mid, f);
	return min(bSearch(s, mid), mid);
}

int main()
{
	input();
	
	sort (b, b + n);
	
	cout << bSearch(1, n + 1) << endl;
	
	sort(ans.begin(), ans.end());
	for (int i = 0; i < x; i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
	
	return 0;
}