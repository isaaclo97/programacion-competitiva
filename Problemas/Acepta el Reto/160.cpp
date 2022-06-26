#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int arr[n][n];
        int c=0,center=0;
        int flag=true,flag2=true;
        for(int i=0; i<n;i++)
            for(int j=0; j<n;j++) {cin>>arr[i][j]; if(arr[i][j]==0) c++;}
        for(int i=0; i<n&&(flag||flag2);i++)
        {
            for(int j=0; j<n&&(flag||flag2);j++)
            {
               if(center==j) continue;
               if(center<j) if(arr[i][j]!=0) flag2=false;
               if(center>j) if(arr[i][j]!=0) flag=false;
            }
            center++;
        }
        if(flag||flag2) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}
