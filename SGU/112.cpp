#include<iostream>


using namespace std;

const int MAX_A=1000+5;

string cl(string a)
{
	int sum=0;
	string b="";
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]!='0')
			break;
		else
			sum++;
	}
	for(int i=sum; i<a.size(); i++)
		b+=a[i];
	return b;
}

string mult(string a, string b)
{
	int asize=a.size(), bsize=b.size();
	long long p[MAX_A]={0};
	string c, d, r, q;
	for(int i=asize-1; i>=0; i--)
		c+=a[i];
	for(int i=bsize-1; i>=0; i--)
		d+=b[i];
	for(int i=0; i<bsize; i++) 
		for(int j=0; j<asize; j++)
			p[i+j]+=(d[i]-'0')*(c[j]-'0');
	for(int i=0; i<asize+bsize; i++)
	{
			r+=p[i]%10+'0';
			p[i+1]+=p[i]/10;
	}
	for(int i=r.size()-1; i>=0; i--)
		q+=r[i];
	return 	cl(q);
}

string sub(string a, string b)
{
	int asize=a.size(), bsize=b.size(), f;
	bool m=0;
	string c, d, r, q;
	for(int i=asize-1; i>=0; i--)
		c+=a[i];
	for(int i=bsize-1; i>=0; i--)
		d+=b[i];
	for(int i=0; i<asize; i++)
	{
		f=(d[i]-'0')-(c[i]-'0')-m;
		if(f<0)
		{
			m=1;
			f=f+10;
		}
		else
			m=0;
		r+=f+'0';
	}
	for(int i=asize; i<bsize; i++)
	{		
		f=(d[i]-'0')-m;
		if(f<0)
		{
			m=1;
			f=f+10;
		}
		else
			m=0;
		r+=f+'0';
	}
	for(int i=r.size()-1; i>=0; i--)
		q+=r[i];
	if(cl(q)=="")
		q='0';
	else
		q=cl(q);
	return q;
}

int ch(string a)
{
    int b=0;
    for(int i=0; i<a.size(); i++)
        b= b*10 + a[i]- '0';
    return b;
}

int main()
{
	string a, b, c, d, r;
	cin>>a>>b;
	c=a;
	d=b;
	int ap= ch(a);
    int bp= ch(b);
	for(int i=0; i<bp-1; i++)
        c= mult(c ,a);
    for(int i=0; i<ap-1; i++)
        d= mult(d, b);
    int cs= c.size(), ds= d.size();
    if(cs<ds)
    {
        r+="-";
        r+= sub(c, d);
    }
    else if(cs>ds)
        r= sub(d, c);
    else
    {
        int i;
        for(i=0; i<cs; i++)
            if( c[i]!=d[i])
                break;
        if (c[i]>=d[i])
            r= sub(d, c);
        else
        {
            r+="-";
            r+=sub(c, d);
        }
    }
    cout<<r<<endl;
	system("pause");
	return 0;
}
