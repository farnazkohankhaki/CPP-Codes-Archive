#include <iostream>
#include <vector>

using namespace std;

struct BigNum {
	vector<int> a;

	BigNum() {
		a.push_back(0);
	}
	BigNum(int x) {
		if (x == 0)
			push(0);
		for (; x != 0; x /= 10)
			push(x%10);
	}
	BigNum (string s) {
		for (int i= s.size()-1; i >= 0; i--)
			push(s[i]-'0');
	}

	int size() {
		return a.size();
	}
	void push(int x) {
		a.push_back(x);
	}
	void push(int num, int x) {
		for (int i= 0; i < num; i++)
			push(x);
	}
	int & end() {
		return a[size()-1];
	}
	void dahBarYek() {
		for (int i= 0; i < size()-1; i++) {
			a[i+1] += a[i]/10;
			a[i] %= 10;
		}
		extend();
	}
	void extend() {
		while (end() > 10) {
			int x = end();
			end() = x%10;
			push(x/10);
		}
	}
	void saf() {
		while (end() == 0 && size() > 1)
			a.pop_back();
	}
	void reverse() {
		for (int i= 0; i < size()/2; i++)
			swap(a[i], a[size()-i-1]);
	}
	bool isEven() {
		return (a[0]%2 == 0);
	}


	BigNum operator +(BigNum y) {
		BigNum x = *this;

		x.push(y.size()-x.size(), 0);

		for (int i= 0; i < y.size(); i++)
			x.a[i] += y.a[i];

		x.dahBarYek();

		return x;
	}

	BigNum operator *(BigNum y) {
		BigNum x;

		x.push(size()+y.size(), 0);

		for (int i= 0; i < size(); i++)
			for (int j= 0; j < y.size(); j++)
				x.a[i+j] += a[i]*y.a[j];

		x.dahBarYek();
		x.saf();

		return x;
	}

	bool operator <(BigNum y) {
		if (size() != y.size())
			return size() < y.size();
		for (int i= size()-1; i >= 0; i--)
			if (a[i] != y.a[i])
				return a[i] < y.a[i];
		return false;

	}
	bool operator ==(BigNum y) {
		return !((*this) < y) && !(y < (*this));
	}

	BigNum divide2() {
		BigNum x;

		for (int i= size()-1; i > 0; i--) {
			x.push(a[i]/2);
			a[i-1] += 10*(a[i]%2);
		}
		x.push(a[0]/2);

		x.reverse();
		x.saf();

		return x;
	}
	BigNum bsearch(BigNum s, BigNum t, BigNum y) {	// [s, t)
		if (s+1 == t)
			return s;
		
		BigNum mid = s+t;
		mid = mid.divide2();

		if ((*this) < mid*y)
			return bsearch(s, mid, y);
		return bsearch(mid, t, y);
	}

	BigNum operator /(BigNum y) {
		if (y == 2)
			return divide2();
		return bsearch(0, *this, y);
	}

	BigNum pow(BigNum y) {
		BigNum x = 1;
		BigNum t = (*this);

		while (!(y == 0)) {
			y.write();
			if (!y.isEven())
				x = x*t;
			t = t*t;
			y = y/2;
		}

		return x;
	}

	void write() {
		for (int i= size()-1; i >= 0; i--)
			cout << a[i];
		cout << endl;
	}
};

int main() {
	BigNum a(142133), b(4213);
	BigNum c = a.pow(b);
	c.write();

	return 0;
}