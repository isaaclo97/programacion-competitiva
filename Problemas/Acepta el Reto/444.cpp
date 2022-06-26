#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,limite;
    while(scanf("%d%d",&a,&limite) && (a!=0||limite!=0))
    {
    int arr[a];
    for (int i=0;i<a;i++){
        cin>>arr[i];
    }
    int maximo=0;
        int sum=0,aux=0,salir=0;
        for (int i=0;i<a;i++)
        {
            if(arr[i]==1)
            {
                for(int j=i; j<a;j++)
                {
                    sum++; salir=j;
                    if(arr[j]!=0)
                    {
                    aux=0;
                    maximo= max(maximo,sum);
                    }
                    if(arr[j]==0) aux++;
                    if(aux>limite) break;
                }
                i=salir;
                sum=0; aux=0;
            }
        }
        printf("%d\n",maximo);
    }
    return 0;
}
