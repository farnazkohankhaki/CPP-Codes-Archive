#include<iostream>
using namespace std;
int main()
{
    int a,n,sum=0;
    cin>>n;
    sum=((n-n%3)/3)*2;
    if(n%3==2)
        sum++; 
    cout<<sum<<endl;
    system("pause");
    return 0;
}       
