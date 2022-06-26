#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    while(scanf("%d",&a)&&a!=0)
    {
        bool puede=true;
        while (a>1)
        {
            if(a%5==1) break;
            if(a%3==0) a/=3;
            else a-=5;
            if(a<1) puede=false;
        }
        if(puede)
            cout<<"SI\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
