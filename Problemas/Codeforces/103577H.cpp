
#include<bits/stdc++.h>
#define mid ((l+r)/2)
using namespace std;
typedef double db;
db d;
db gett(db x1,db v1,db x2,db v2)
{
	db l=0,r=fabs((x1-x2)/(v1-v2));
	for(int i=1;i<=100;i++)
	{
		if(v2<0)
		{
			if(x2+v2*mid-min(d,x1+v1*mid)>1e-10)l=mid;
			else r=mid;
		}
		else
		{
			if(x2+v2*mid-min(d,x1+v1*mid)>1e-10)r=mid;
			else l=mid;
		}
	}
	return mid;
}
int main()
{
	db v0,v1,v2,t;
	db x0=0,x1=1,x2=0;
	cin>>d>>v0>>v1>>v2>>t;
	while(1)
	{
		db r=gett(x1,v1,x2,v2);
		if(r-t>1e-8||fabs(r-t)<=1e-8){printf("%.12f\n",x2+v2*t);return 0;}
		x2=x2+v2*r;
		x0=min(d,x0+v0*r);
		x1=min(d,x1+v1*r);
		t-=r;
 
		r=gett(x0,v0,x2,-v2);
		if(r-t>1e-8||fabs(r-t)<=1e-8){printf("%.12f\n",x2-v2*t);return 0;}
		x2=x2-v2*r;
		x0=min(d,x0+v0*r);
		x1=min(d,x1+v1*r);
		t-=r;
		if(fabs(x0-d)<1e-8)break;
	}
	printf("%.12f\n",x2);
	return 0;
}
