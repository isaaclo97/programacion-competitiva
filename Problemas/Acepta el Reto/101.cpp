#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int arr[n][n];
        map<int,int> M;
        for(int i=0; i<n;i++)
            for(int j=0; j<n;j++) { cin>>arr[i][j]; M[arr[i][j]]++; }
        int suma,flag,cm1,flag1;
        flag=suma=cm1=flag1=0;
        //filas
        for(int i=0; i<n && flag1==0 ;i++)
        {
            for(int j=0; j<n && flag1==0 ;j++) { suma+=arr[i][j]; }
            if(flag==0) { flag=1; cm1=suma; }
            if(suma!=cm1) flag1=1;
            suma=0;
        }
        //columnas
        for(int i=0; i<n && flag1==0  ;i++)
        {
            for(int j=0; j<n && flag1==0  ;j++) { suma+=arr[j][i]; }
            if(suma!=cm1) flag1=1;
            suma=0;
        }
        //diagonal principal
        for(int i=0; i<n && flag1==0 ;i++) { suma+=arr[i][i]; }
        if(suma!=cm1) flag1=1;
        //diagonal reversa
        suma=0;
        for(int i=0; i<n && flag1==0 ;i++) { suma+=arr[i][n-i-1]; }
        if(suma!=cm1) flag1=1;
        int corner,cm2=(cm1*4)/n;
        //comprobar numeros
        if(flag1==0)
        {
            flag1=2;
            for(int i=1; i<=n*n && flag1==2;i++) if(M[i]!=1) flag1=0;
            if(flag1!=0)
            {
                corner=arr[0][n-1]+arr[n-1][0]+arr[0][0]+arr[n-1][n-1];
                if(corner!=cm2) { flag1=0; break; }
                int center = n/2;
                if(n%2!=0)
                {
                    if(arr[center][center]*4 != cm2) flag1=0;
                    if((arr[0][center]+arr[center][0]+arr[n-1][center]+arr[center][n-1])!=cm2) flag1=0;
                }
                else
                {
                    center--;
                    if((arr[center][center]+arr[center+1][center+1]+arr[center][center+1]+arr[center+1][center]) != cm2) flag1=0;
                    if((arr[0][center]+arr[0][center+1]+arr[center][0]+arr[center+1][0]+arr[n-1][center]+arr[n-1][center+1]+arr[center][n-1]+arr[center+1][n-1])!=(cm2*2)) flag1=0;
                }
            }
        }
        if(flag1==0) cout<<"DIABOLICO\n";
        else if(flag1==1) cout<<"NO\n";
        else if(flag1==2) cout<<"ESOTERICO\n";
    }
    return 0;
}

