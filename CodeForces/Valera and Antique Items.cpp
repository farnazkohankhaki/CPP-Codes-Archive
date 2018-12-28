#include <iostream>
#include <queue>

using namespace std;

int n, v;
queue <int> q;

int main ()
{
	cin >> n >> v;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		bool ch = true;
		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			if (y < v && ch)
			{
				q.push(i + 1);
				ch = false;
			}
		}
	}
	
	int t = q.size();
	cout << q.size() << endl;
	for (int i = 0; i < t; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	
	return 0;
}