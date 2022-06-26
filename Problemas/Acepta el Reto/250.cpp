#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int arr[1000000];
        int sum,sum1,mini,sol=cases+1; sum=sum1=0;
        mini=INF;
        for(int i=0; i<cases;i++)
        {
            cin>>arr[i];  sum1+=arr[i];
        }
        for(int i=0; i<cases;i++)
        {
            if(abs(sum-sum1)<mini) { sol=i; mini=abs(sum-sum1);}
            sum+=arr[i];
            sum1-=arr[i];
        }
        cout<<sol<<'\n';
    }
    return 0;
}
