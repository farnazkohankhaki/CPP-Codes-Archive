#include <iostream>
using namespace std;


const int MAX_N=1000+8;

void goshad(int a[], int n, int s)
{
	if(n==0)
	{
		for(int i=0; i<s; i++)
			cout<<a[i];
		cout<<endl;
	}
	else if(n==1)
	{
		a[0]=0;
		for(int i=0; i<s; i++)
			cout<<a[i];
		cout<<endl;
		a[0]=1;
		for(int i=0; i<s; i++)
			cout<<a[i];
		cout<<endl;
	}
	else
	{
		a[n-1]=0;
		goshad(a, n-1, s);
		a[n-1]=1;
		a[n-2]=0;
		goshad(a, n-2, s);
	}
}

int main()
{
	int a[MAX_N],  n;
	cin>>n;
	goshad(a, n, n);
	return 0;
}
