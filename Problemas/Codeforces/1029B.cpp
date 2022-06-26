#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n;i++) cin>>arr[i];
    int res=1,sum=1,aux=0;
    for (int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            sum++;
            if(arr[j-1]*2>=arr[j]) { res= max(res,sum); aux=j;}
            else
            {
                i=j-1; sum=1; break;
            }
        }
        if(aux==n-1) break;
    }
    cout<<res<<'\n';
    return 0;
}
