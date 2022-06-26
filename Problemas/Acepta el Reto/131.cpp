#include <bits/stdc++.h>
#define INF 0x3F3F3F3F

using namespace std;
int getCount(int pisA,int baA,int bajA)
{
    int aux1=0,k=2,resultado;
    while(k>1)
    {
    resultado=pisA/baA;
    k=pisA-(resultado*baA)+resultado*bajA;
    aux1+=resultado;
    if(k<=0) break;
    if(k<=baA) { aux1++; break; }
    pisA=k;
    }
    return aux1;
}
int main()
{
    int pisA,pisB,baA,baB,bajB,bajA,k,m;
            while(scanf("%d%d%d%d%d%d",&pisA,&baA,&bajA,&pisB,&baB,&bajB)&&pisA!=0&&pisB!=0)
            {
                if(pisA==0||pisB==0) break;
                if(bajA>=baA && baA<pisA) k=INF;
                else if(baA>=pisA) k=1;
                else k = getCount(pisA,baA,bajA);
                if(bajB>=baB && baB<pisB) m=INF;
                else if(baB>=pisB) m=1;
                else m = getCount(pisB,baB,bajB);
                if(m==INF && k==INF) m=k=0;
                if(m>k) cout<<"YO "<<k<<'\n';
                else if(m<k) cout<<"VECINO "<<m<<'\n';
                else cout<<"EMPATE "<<k<<'\n';
            }
     return 0;
}
