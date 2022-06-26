#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
int main() {
    int n,r;
    while(scanf("%d%d",&n,&r)==2 && n+r)
    {
        int arr[n],res=INF,aux1,res1=0,rec=1;
        for(int i=0; i<n;i++) cin>>arr[i];
        for(int i=0; i<r;i++)
        {
            for(int j=0; j<n;j++)
            {
                cin>>aux1;
                if(aux1!=0)
                res=min(res,(10*arr[j])/aux1);
            }
            if(res1<res) { res1=res; rec=i+1;}
            res=INF;
        }
        cout<<rec<<" "<<res1<<endl;
    }
    return 0;
}
 
