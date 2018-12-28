#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct BigNum 
{
	deque<int> a;
	
	BigNum()
	{
		a.push_back(0);
	}
	
	BigNum(int x)
	{
		if (x == 0)
			push(0);
		for (; x != 0; x /= 10)
			push(x % 10);
	}
	
	BigNum (string s)
	{
		for (int i = s.size() - 1; i >= 0; i--)
			push(s[i] - '0');
	}
	
	int size()
	{
		return a.size();
	}
	
	void push(int x)
	{
		a.push_back(x);
	}
	
	void push(int num, int x)
	{
		for (int i = 0; i < num; i++)
			push(x);
	}
	
	int & end()
	{
		return a[size() - 1];
	}
	
	void dahBarYek()
	{
		for (int i = 0; i < size() - 1; i++)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		extend();
	}
	
	void extend()
	{
		while (end() >= 10) {
			int x = end();
			end() = x % 10;
			push(x / 10);
		}
	}
	
	void saf()
	{
		while (end() == 0 && size() > 1)
			a.pop_back();
	}
	
	BigNum operator + (BigNum y)
	{
		BigNum x = *this;
		
		x.push(y.size() - x.size(), 0);
		
		for (int i = 0; i < y.size(); i++)
			x.a[i] += y.a[i];
		
		x.dahBarYek();
		
		return x;
	}
	
	BigNum operator * (BigNum y)
	{
		BigNum x;
		
		x.push(size()+y.size(), 0);
		
		for (int i = 0; i < size(); i++)
			for (int j = 0; j < y.size(); j++)
				x.a[i+j] += a[i]*y.a[j];
		
		x.dahBarYek();
		x.saf();
		
		return x;
	}
	
	bool operator < (BigNum y)
	{
		if (size() != y.size())
			return size() < y.size();
		for (int i = size() - 1; i >= 0; i--)
			if (a[i] != y.a[i])
				return a[i] < y.a[i];
		return false;
	}	
	
	void write()
	{
		for (int i = size() - 1; i >= 0; i--)
			cout << a[i];
		cout << endl;
	}
};

int findSize (BigNum x, int s)
{
	string t = "1";
	for (int i = 0; i < s; i++)
		t += '0';
	
	BigNum a(t), d(10);
	
	while (!(x < a * a * d * d) )
		a = a * d;
	
	return a.a.size();
}

string makeSN (int num, int x)
{
	string r;
	while (num > 0)
	{
		r += num % 10 + '0';
		num /= 10;
	}
	for (int i = 0; i < r.size() / 2; i++)
		swap (r[i], r[r.size() - i - 1]);
	for (int i = 0; i < x; i++)
		r += '0';
	return r;
}

int main() 
{
	string s;
	cin >> s;
	BigNum x(s);

	int size = findSize (x, s.size() / 2 - 1);

	string s1 = makeSN(1, size - 1);
	BigNum ans(s1), r(0), r2(0), two(2);
	for (int i = size - 1; i >= 0; i--)
	{
		BigNum f = r2, g = two * r;
		int a = 0, b = 10;
		while (1)
		{
			int c = (a + b) / 2; 
			string ks = makeSN(c * c, 2 * i);
			BigNum m, k = (ks), c2(c * c), cp(c);
			g = g * cp;
			for (int j = 0; j < i; j++)
				g.a.push_front(0);
			m = k + g + f;
			
			r2 = m;
			g = two * r;

			if (b - a <= 1)
				break;
			if (x < m)
				b = c;
			else
				a = c;
		}
		ans.a[i] = a;
		r = ans;
	}

	ans.write();
	
	return 0;
}