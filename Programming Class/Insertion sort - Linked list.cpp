#include <iostream>

using namespace std;

class node
{
	public:
	int val;
	node * next;
	node * prev;
};

int main()
{
	int n, a;
	cin >> n;
	node * start = new node ();
	start -> val = -1 * (1 << 25);
	for (int i = 0; i < n; i++)
	{
		node * tmp = start;
		cin >> a;
		while (tmp -> val < a && tmp -> next != NULL){
			
			tmp = tmp -> next;
		}
		if (tmp -> val < a)
		{
			node * nn = new node ();
			nn -> val = a;
			nn -> next = NULL;
			nn -> prev = tmp;
			tmp -> next = nn;
		}
		else	
		{
		node * nn = new node ();
		nn -> val = a;
		nn -> next = tmp;
		nn -> prev = tmp -> prev;
		if (tmp -> prev != NULL)
			nn -> prev -> next = nn;
		if (tmp -> next != NULL)
			nn -> next -> prev = nn;
		}
		
	}
	node * tmp = start;
	while (tmp -> next != NULL)
	{
		tmp = tmp -> next;
		cout << tmp -> val << " ";
	}
	cout << endl;
	return 0;
}