#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        long long int minV=INF,min2V=INF,maxV=-INF,max2V=-INF,flag=1,flag2=1;
        long long int arr[cases];
        for(int i=0; i<cases;i++) {cin>>arr[i]; maxV=max(arr[i],maxV);}
        for(int i=0; i<cases;i++) { if(flag==0 || arr[i]!=maxV) max2V=max(arr[i],max2V); if(arr[i]==maxV) flag=0; }
        for(int i=0; i<cases;i++)  minV=min(arr[i],minV);
        for(int i=0; i<cases;i++) {if(flag2==0 || arr[i]!=minV) min2V=min(arr[i],min2V); if(arr[i]==minV) flag2=0; }
        if(min2V == INF) cout<<minV*maxV<<endl;
        else if(min2V*minV > maxV * max2V) cout<<min2V*minV<<endl;
        else  cout<<max2V*maxV<<endl;
    }
    return 0;
}
