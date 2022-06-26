#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int arr[cases];
        set<int> S;
        for(int i=0; i<cases;i++) cin>>arr[i];
        for(int i=0; i<cases;i++)
            for(int j=i+1; j<cases;j++)
                S.insert(abs(arr[i]-arr[j]));
        int flag=0;
        for(auto s:S)
            if(flag==0) {flag=1; cout<<s;}
            else cout<<" "<<s;
        cout<<'\n';
    }
    return 0;
}
