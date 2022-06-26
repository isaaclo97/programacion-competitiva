#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int n,res=0,ini,ini1,fin,num,acu=0;
        scanf("%d",&n);
        for(int i=0; i<n;i++)
        {
            scanf("%d",&num);
            if(acu==0) ini1=i;
            if(num!=0) acu++;
            else acu=0;
            if(acu>res) {res=acu; ini=ini1; fin=i;}
        }
        if(res==0) printf("SIGUE BUSCANDO\n");
        else printf("%d -> [%d,%d]\n",fin-ini+1,ini,fin);
    }
    return 0;
}
