#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b; cin>>a; cin>>b;
    int flag=1,resu=a.length()+b.length();
    int al=a.length(); int bl=b.length();
    if (a==b) { flag=0; resu=0;}
    else if(al==bl) {
        for(int i=al; i>=0;i--) {
            if(a[i]!=b[i]) { if(flag==1) resu=(i+1)*2; break;} else flag=1;
        }
    }
    else
    {
        int aux=0,aa=al,bb=bl; aa--; bb--;
        for(int i=min(aa,bb); i>=0;i--){
            if(a[aa]!=b[bb]) break; else flag=1; aux++; aa--; bb--;
        }
        if(flag==1)
        {
            resu=(min(al,bl)-aux)*2;
            if(al>bl) resu+=(al-bl);
            else resu+=(bl-al);
        }
    }
    cout<<resu<<'\n';
    return 0;
}
