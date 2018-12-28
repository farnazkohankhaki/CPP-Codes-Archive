#include<iostream>
using namespace std;
int pow(int a, int b)
{
    if(b==0)
        return 1;
    else
    {
        if(b%2==1)
            return pow(a,b/2)*pow(a,b/2)*a;
        else
            return pow(a,b/2)*pow(a,b/2);
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
    return 0;
}
