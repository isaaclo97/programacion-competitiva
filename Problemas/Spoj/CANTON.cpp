#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    cin>>i;
    while(i--)
    {
        int k=1,p=1,u=2;
 
        bool bajar=false;
        bool arriba=false;
        bool derecha=true;
        bool baja1=false;
        int m,ko;
        cin>>m;
        ko=m;
        m--;
        while(m--)
        {
            if(derecha)
            {
            p++;
            derecha=false;
            arriba=false;
            baja1=true;
            continue;
            }
            if(arriba)
            {
                k--;
                p++;
                if(p==u)
                {
                    u++;
                    derecha=true;
                }
                continue;
            }
            if(bajar)
            {
                k++;
                bajar=false;
                arriba=true;
                continue;
            }
            if(baja1)
                {
                    p--;
                    k++;
                    if(k==u)
                    {
                    bajar=true;
                    u++;
                    }
                    continue;
                }
            }
           cout<<"TERM "<<ko<<" IS "<<k<<"/"<<p<<endl;
    }
    return 0;
} 
