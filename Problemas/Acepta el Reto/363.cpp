#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    while(scanf("%lf",&n)==1 && n!=0)
    {
       int cases,aux,res=0; cin>>cases;
       for(int i=0; i<cases;i++) {cin>>aux; res+=aux;}
       double to = res/n;
       if(to==(int)to) cout<<(int)to<<'\n';
       else cout<<(int)to+1<<'\n';
    }
    return 0;
}
