#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3 && (a!=0 || b!=0 || c!=0))
    {
        if(a>=b && a>=c) { if(sqrt(b*b + c*c)==a) cout<<"right\n"; else cout<<"wrong\n"; }
        else if(b>=a && b>=c) { if(sqrt(a*a + c*c)==b) cout<<"right\n"; else cout<<"wrong\n"; }
        else if(c>=a && c>=b) { if(sqrt(b*b + a*a)==c) cout<<"right\n"; else cout<<"wrong\n"; }
    }
return 0;
}
