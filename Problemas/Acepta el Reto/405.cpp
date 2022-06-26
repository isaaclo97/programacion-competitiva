#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int num,num2,aux;
    while(scanf("%d",&num)==1&&num!=0)
    {
        bool put = false;
        aux=num;
        while(scanf("%d",&num2)==1)
        {
            if(aux==num2-1) put=true;
            else{
                 if(put) {cout<<num<<"-"<<aux; num=num2; put=false; if(num2!=0) cout<<",";}
                 else { cout<<aux; num=num2; if(num2!=0) cout<<",";}
            }
            aux=num2;
            if(num2==0) break;
        }
        cout<<'\n';
    }
    return 0;
}
