#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);int arr[cases];
    int par,impar; par=impar=0;
    for(int i=0;i<cases;i++) { scanf("%d",&arr[i]); if(arr[i]%2==0) par++; else impar++;}
    if(abs(par-impar)<2) printf("0\n");
    else {
        long long int sum = 0;
        sort(arr,arr+cases);
        if (par>impar) { for(int i=0; i<cases && abs(par-impar)>1;i++) if(arr[i]%2==0) { sum+=arr[i]; par--; } }
        else {
            for(int i=0; i<cases && abs(par-impar)>1;i++) if(arr[i]%2!=0) { sum+=arr[i]; impar--; }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
