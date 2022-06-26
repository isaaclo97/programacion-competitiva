#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases,flag=0;
    cin>>cases;
    int arr[cases];
    int aux1[3],aux[3];
    for(int i=0; i<cases;i++)
        cin>>arr[i];
    for(int i=0; i<cases;i++)
    {
        aux[0] = arr[i];
        aux1[0] = i+1;
        aux[1] = arr[arr[i]-1];
        aux1[1]= arr[i];
        aux[2] = arr[arr[arr[i]-1]-1];
        aux1[2] = arr[arr[i]-1];
        sort(aux,aux+3);
        sort(aux1,aux1+3);
        if(aux[0]==aux1[0]&&aux[1]==aux1[1]&&aux[2]==aux1[2]) {flag=1; break;}
    }
    if(flag==1) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
