#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int k,n; scanf("%d%d",&k,&n);
    int arr[k]; memset(arr,0,sizeof(arr));
    int maxi=0,mini=INF,medio=0;
    int num1,num2,flag; num1=num2=flag=-1;
    for(int i=0; i<n;i++)
    {
        int x; scanf("%d",&x);
        arr[x-1]++;
    }
    for(int i=0; i<k;i++) {
        if(maxi<arr[i]) {maxi=arr[i]; num1=i+1;}
        if(mini>arr[i]) {mini=arr[i]; num2=i+1;}
    }
    if(n%k == 0) medio = n/k;
    else if(n%k==1) medio = n/k;
    else if(n%k==k-1) medio = (n+1)/k;
    else medio = INF;

    if(maxi==medio) flag=1;
    else if(mini==medio) flag=0;
    else if((maxi-1)==medio && (mini+1) == medio) flag=2;

    if(flag==-1) printf("*\n");
    else if(flag==0)printf("-%d\n",num1);
    else if(flag==1) printf("+%d\n",num2);
    else printf("-%d +%d\n",num1,num2);
    return 0;
}
