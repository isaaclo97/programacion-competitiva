#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d",&n)==1 && n!=0)
    {
        char a;
        char ma[n][n];
        for(int i=0; i<n;i++)
           for(int j=0; j<n;j++) cin>>ma[i][j];
        while(cin>>a && a!='x')
        {
           char maux[n][n];
           scanf("%d",&m);
           if(a=='c')
           {
                if(m<0)
                {
                    for(int i=0; i<n;i++) maux[(n+(i-1)%n)%n][abs(m)-1]=ma[i][abs(m)-1];
                    for(int i=0; i<n;i++) ma[i][abs(m)-1]=maux[i][abs(m)-1];
                }
                else
                {
                    for(int i=0; i<n;i++) maux[(i+1)%n][abs(m-1)]=ma[i][abs(m-1)];
                    for(int i=0; i<n;i++) ma[i][abs(m-1)]=maux[i][abs(m-1)];
                }
           }
           else
           {
               if(m<0)
               {
                  for(int i=0; i<n;i++) maux[abs(m)-1][(n+(i-1)%n)%n]=ma[abs(m)-1][i];
                  for(int i=0; i<n;i++) ma[abs(m)-1][i]=maux[abs(m)-1][i];
               }
               else
               {
                   for(int i=0; i<n;i++) maux[abs(m-1)][(i+1)%n]=ma[abs(m-1)][i];
                   for(int i=0; i<n;i++) ma[abs(m-1)][i]=maux[abs(m-1)][i];
               }
           }
        }
        for(int i=0; i<n;i++)
        {
           for(int j=0; j<n;j++) cout<<ma[i][j];
           printf("\n");
        }
        printf("---\n");
    }
    return 0;
}
