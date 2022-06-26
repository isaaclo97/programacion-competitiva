#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int num,n,aux,sum,res=0; cin>>num;
        cin>>n;
        int arr[num+1];
        memset(arr,0,sizeof(arr));
        while(n--)
        {
            cin>>sum;
            aux=sum;
            while(aux<=num)
            {
                if(!(aux%7==6 || aux%7==0)&&arr[aux]==0) {arr[aux]=1; res++;}
                aux+=sum;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
