#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int sum,aux=1;
    while(scanf("%d",&sum)==1 && sum>-1)
    {
        int arr[12],num;
        printf("Case %d:\n",aux++);
        for(int i=0; i<12;i++) cin>>arr[i];
        for(int i=0; i<12;i++)
        {
            cin>>num;
            if(num<=sum) { cout<<"No problem! :D\n"; sum=arr[i]+sum-num;}
            else { cout<<"No problem. :(\n"; sum+=arr[i];}
        }
    }
    return 0;
}
