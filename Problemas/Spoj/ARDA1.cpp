#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int n,m,n1,m1;
    while(scanf("%d%d",&n1,&m1)==2)
    {
        bool checked=false;
        char arr[n1][m1];
        for(int i=0; i<n1;i++)
            for(int j=0; j<m1;j++) cin>>arr[i][j];
        cin>>n>>m;
        char mapa[n][m];
        for(int i=0; i<n;i++)
            for(int j=0; j<m;j++) cin>>mapa[i][j];
        //check
        for(int i=0; i<n-n1+1;i++)
            for(int j=0; j<m-m1+1;j++)
            {
                if(mapa[i][j]==arr[0][0])
                {
                    //check
                    bool check = true;
                    for(int i1=0; i1<n1&&check;i1++)
                        for(int j1=0; j1<m1&&check;j1++)
                        {
                            if(mapa[i1+i][j1+j]!=arr[i1][j1])
                            check=false;
                        }
                    if(check) {printf("(%d,%d)\n",i+1,j+1); checked=true;}
                }
            }
        if(!checked) cout<<"NO MATCH FOUND...\n";
    }
    return 0;
} 
