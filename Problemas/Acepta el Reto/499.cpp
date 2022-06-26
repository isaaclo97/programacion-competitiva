#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,C,FF,PF,V;
    while(scanf("%d%d%d",&a,&b,&c)==3 && (a!=0 || b!=0 || c!=0))
    {
        int matrix[a+1][b];
        for(int i=0; i<a;i++)
            for(int j=0; j<b;j++)
                matrix[i][j]=0;
        for(int i=0; i<c;i++)
        {
            cin>>C>>PF>>FF>>V;
            matrix[PF][C]+=V;
            matrix[FF+1][C]+=(-V);
        }
        for(int i=0; i<b;i++)
        {
            int val = 0;
            for(int j=0; j<a;j++)
            {
                val+=matrix[j][i];
                matrix[j][i]=val;
            }
        }
        for(int i=0; i<a;i++)
        {
            for(int j=0; j<b;j++)
            {
                if(j==0) cout<<matrix[i][j];
                else cout<<" "<<matrix[i][j];
            }
            cout<<endl;
        }

    }
    return 0;
}
