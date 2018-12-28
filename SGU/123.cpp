#include<iostream>
using namespace std;
int main()
{
    int n,a=1,b=1,c,sum=2;
    cin>>n;
    if(n<2)
        sum=1;
    else
        for(int i=1; i<n-1; i++)
        {
            c=b;
            b=b+a;
            a=c;
            sum=sum+b;
        }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
        
