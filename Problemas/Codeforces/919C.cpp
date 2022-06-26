#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main() {
    int n,m,c,res=0,count=0;
    cin>>n>>m>>c;
    char arr[n][m];
    bool flag=false;
    for(int i=0; i<n;i++)
        for(int j=0; j<m;j++) cin>>arr[i][j];
    //row
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(flag) if(arr[i][j]=='.') count++; else {count=0; flag=false;}
            else if(arr[i][j]=='.') {flag=true; count++;};
            if(count>=c) res++;
        }
        flag=false; count=0;
    }
    count=0; flag=false;
    //column
    for(int i=0; i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flag) if(arr[j][i]=='.') count++; else {count=0; flag=false;}
            else if(arr[j][i]=='.') {flag=true; count++;};
            if(count>=c) res++;
        }
        flag=false; count=0;
    }
    if(c==1) res/=2;
    cout<<res<<endl;
    return 0;
}

