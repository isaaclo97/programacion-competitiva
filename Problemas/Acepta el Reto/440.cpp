#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int g=0,gp=INF,gg=0,aux,cabeza,aux2=0;
        for(int i=0; i<cases;i++)
        {
            cin>>aux;
            if(i==0)
            {
                cabeza=aux;
                aux2++;
                g++;
            }
            else
            {
                if(aux>=cabeza)
                {
                    aux2++;
                }
                else
                {
                    g++;
                    cabeza=aux;
                    gp=min(gp,aux2);
                    gg=max(gg,aux2);
                    aux2=1;
                }
            }
        }
      gp=min(gp,aux2);
      gg=max(gg,aux2);
      cout<<g<<" "<<gp<<" "<<gg<<endl;
    }
    return 0;
}
