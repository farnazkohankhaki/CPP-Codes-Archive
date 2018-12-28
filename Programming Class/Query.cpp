// be name khoda
//mr.mahini

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100*1000;
const int MIN_HEAP = 0 , MAX_HEAP = 1;
const int COMMAND_NUM = 6;
const string COMMAND[] = {"add", "min", "max", "delmin", "delmax", "end"};
enum {add= 1, minim, maxim, delmin, delmax, end};

int n;

struct Reference {
	int key;
	int ref[2];
} a[MAXN];

struct HeapNumber {
	int type;
	int index;

	HeapNumber() {}
	HeapNumber(int x, int _type) {
		index = x;
		type = _type;
	}

	int getKey() const {
		return a[index].key;
	}
	void swp(HeapNumber &x) {	// swap
		swap(index, x.index);
		swap(a[index].ref[type] , a[x.index].ref[type]);
	}
	bool operator < (const HeapNumber &x) const {
		if (type == MIN_HEAP)
			return getKey() < x.getKey();
		else
			return getKey() > x.getKey();
	}
};

struct Heap {
	int type;
	vector<HeapNumber> tree;

	Heap () {
		tree.push_back(HeapNumber());
	}
	HeapNumber getRoot() {
		return tree[1];
	}
	int getSize() {
		return tree.size()-1;
	}
	int heap_up(int i) {
		while (i > 1 && tree[i] < tree[i/2]) {
			tree[i].swp(tree[i/2]);
			i /= 2;
		}
		return i;
	}
	int heap_down(int i) {
		while (2*i <= getSize()) {
			int mini = 2*i;
			if (2*i+1 <= getSize() && tree[2*i+1] < tree[mini])
				mini = 2*i+1;
			if (tree[mini] < tree[i]) {
				tree[i].swp(tree[mini]);
				i = mini;
			} else
				break;
		}
		return i;
	}
	void add(int x) {
		HeapNumber num = HeapNumber(x,type);
		tree.push_back(num);
		a[num.index].ref[type] = getSize();
		heap_up(getSize());
	}
	void remove(int ind) {
		tree[ind].swp(tree[getSize()]);
		tree.pop_back();
		ind = heap_up(ind);
		heap_down(ind);
	}
	void write() {
		cerr << "Heap " << type << " : ";
		for (int i= 1; i <= getSize(); i++)
			cerr << tree[i].getKey() << " ";
		cerr << endl;
	}
};

Heap h[2];

void addNumber(int x) {
//	cerr << "add " << x << endl;
	a[n].key = x;
	for (int i= 0; i < 2; i++)
		h[i].add(n);
	n++;
}

void removeMin() {
//	cerr << "remove min" << endl;
	int maxIndex = a[h[0].getRoot().index].ref[MAX_HEAP];
	h[0].remove(1);
	h[1].remove(maxIndex);
}

void removeMax() {
//	cerr << "remove max" << endl;
	int minIndex = a[h[1].getRoot().index].ref[MIN_HEAP];
	h[1].remove(1);
	h[0].remove(minIndex);
}

void init() {
	h[0].type = MIN_HEAP;
	h[1].type = MAX_HEAP;
}

int getCommand() {
	string s;
	cin >> s;
	for (int i= 0; i < COMMAND_NUM; i++)
		if (s == COMMAND[i])
			return i+1;
	return 0;
}

int main() {
	init();
	for (int x; (x= getCommand());) {
		switch (x) {
			case add:
				int num;
				cin >> num;
				addNumber(num);
				break;
			case minim:
				cout << "min: " << h[0].getRoot().getKey() << endl;
				break;
			case maxim:
				cout << "max: " << h[1].getRoot().getKey() << endl;
				break;
			case delmin:
				removeMin();
				break;
			case delmax:
				removeMax();
				break;
			case end:
				return 0;
		}
		/*
		cerr << "a : ";
		for (int i= 0; i < n; i++)
			cerr << a[i].key << " (" << a[i].ref[0] << "," << a[i].ref[1] << ") - ";
		cerr << endl;
		for (int i= 0; i < 2; i++)
			h[i].write();
		cerr << "=============" << endl;
		*/
	}
	return 0;
}
