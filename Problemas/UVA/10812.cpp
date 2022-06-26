#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
    int cases; cin>>cases;
    while(cases--)
    {
        int s,t,x,y;
        scanf("%d %d",&s,&t);
        y=abs(s-t)/2;
        x=s-y;
        if((x+y==s) && (abs(x-y)==t)) printf("%d %d\n",max(x,y),min(x,y));
        else printf("impossible\n");
    }
    return 0;
}
