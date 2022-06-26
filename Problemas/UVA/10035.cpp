#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b; cin>>a>>b;
    while(a!="0" || b!="0")
    {
        int res=0,cnt=0;
        int n,n1; n=a.length(); n1=b.length(); n--; n1--;
        for(int i = min(a.length()-1,b.length()-1); i>=0; i--)
        {
            if((a[n]-'0' + b[n1]-'0'+cnt)>9) { res++; cnt=1;}
            else cnt=0;
            n--; n1--;
        }
        for(int i=n;i>=0;i--){
            if((a[i]-'0'+cnt)>9) { res++; cnt=1;}
            else break;
        }
        for(int i=n1;i>=0;i--){
            if((b[i]-'0'+cnt)>9) { res++; cnt=1;}
            else break;
        }
        if(res==0) cout<<"No carry operation.\n";
        else if(res==1) cout<<"1 carry operation.\n";
        else cout<<res<<" carry operations.\n";
        cin>>a>>b;
    }
    return 0;
}
