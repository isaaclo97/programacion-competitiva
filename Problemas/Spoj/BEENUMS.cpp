#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
map<long long,bool> a;
 
int main()
{
    a[1]=true;
    long long b=1,c=1,n;
    while(b<=1000000000)
    {
        b=3*c*(c+1)+1;
        c++;
        a[b]=true;
    }
    while(scanf("%lld",&n)==1&&n!=-1)
    {
        if(a[n]) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
} 
