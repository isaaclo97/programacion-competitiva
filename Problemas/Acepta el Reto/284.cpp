#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int cases; cin>>cases;
    while(cases--)
    {
        int n,p; cin>>n>>p;
        if(n>p) printf("DEBE %d\n",n-p);
        else
        {
            p=p-n;
            if(200<=p) { cout<<p/200<<" "; p=p-(p/200)*200;}
            else cout<<0<<" ";
            if(100<=p) { cout<<p/100<<" "; p=p-(p/100)*100;}
            else cout<<0<<" ";
            if(50<=p) { cout<<p/50<<" "; p=p-(p/50)*50;}
            else cout<<0<<" ";
            if(20<=p) { cout<<p/20<<" "; p=p-(p/20)*20;}
            else cout<<0<<" ";
            if(10<=p) { cout<<p/10<<" "; p=p-(p/10)*10;}
            else cout<<0<<" ";
            if(5<=p) { cout<<p/5<<" "; p=p-(p/5)*5;}
            else cout<<0<<" ";
            if(2<=p) { cout<<p/2<<" "; p=p-(p/2)*2;}
            else cout<<0<<" ";
            if(1<=p) { cout<<p/1<<endl; p=p-(p/1)*1;}
            else cout<<0<<endl;
        }
    }
    return 0;
}
