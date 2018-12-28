#include<iostream>
using namespace std;
struct biginteger
{
    int size;
    string num;
    biginteger(string s="")
    {
        size=s.size();
        for(int i=size-1; i>=0; i--)
			num+=s[i];
    }
    biginteger add(biginteger b)
    {
        bool k=0;
		int f=0;
		biginteger c;
        for(int i=0; i<size; i++)
        {
			f=(num[i]-'0')+(b.num[i]-'0')+k;
			if(f>9)
			{
				f=f-10;
				k=1;
			}
			else
				k=0;
			c.num+=f+'0';
		}
		for(int i=size; i<b.size; i++)
		{
			f=b.num[i]-'0'+k;
			if(f>9)
			{
				f=0;
				k=1;
			}
			else
				k=0;
			c.num+=f+'0';
		}
		if(k)
			c.num+=k+'0';
		c.size=8;
		return c;
	}  
};
int main()
{
    string s1, s2, m1, m2;
    cin>>s1>>s2;		
    biginteger a(s1), b(s2);
	m2=a.add(b).num;
	for(int i=m2.size()-1; i>=0; i--)
		m1+=m2[i];
    cout<<m1<<endl;
    system("pause");
    return 0;
}
