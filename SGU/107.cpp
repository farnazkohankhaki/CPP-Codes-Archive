#include<iostream>
using namespace std;
// in ghesmat baraaye, estefaade shodan too code e! va jozE az barnaameye asli nis!
/*
int main()
{		
	long long m;
    int sum=0;
    for(long long i=1; i<1000000000; i++)
	{	
		m=i*i;
		if(m%1000000000==987654321)
			sum++;
	}
    cout<<sum;
    system("pause");
    return 0;
}
*/
int main()
{
    int n, m;
    cin>>n;
    if(n<9)
    cout<<0;
    if(n==9)
        cout<<8;
    if(n>9)
    {
        n=n-10;
        cout<<8*9;
        for(int i=0; i<n; i++)
            cout<<0;
    }
    system("pause");
    return 0;
} 

