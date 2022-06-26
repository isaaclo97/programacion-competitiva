#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 &&cases!=0)
    {
        int arr[cases],res=0,flag=0;
        for(int i=0; i<cases;i++) cin>>arr[i];
        for(int i=0; i<cases;i++)
        {
            int aux1 = arr[i];
            int act= 0;
            for(int j=i+1; j<cases;j++)
            {
                act+=arr[j];
                if(act>aux1) break;
            }
                if(act==aux1){ flag=1; res=i+1; break;}
        }
        if(flag==1) cout<<"SI "<<res<<endl;
        else cout<<"NO\n";
    }
    return 0;
}
