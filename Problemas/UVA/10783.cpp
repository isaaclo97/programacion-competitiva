#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
    int cases,c=1;
    cin>>cases;
    while(cases--)
    {
        int a,b,res=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        {
            if(i%2!=0) res+=i;
        }
        printf("Case %d: %d\n",c++,res);
    }
    return 0;
}
