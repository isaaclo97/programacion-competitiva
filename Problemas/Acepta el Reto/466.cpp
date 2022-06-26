#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        string a,b,res; cin>>a>>b;
        int add = abs((int)a.length()-(int)b.length());
        int al = a.length(); al--;
        int bl = b.length(); bl--;
        int m = min(al,bl);
        int carr = 0;
        int addi;
        for(int i=0; i<=m;i++)
        {
            int fi = (a[al]-'0')*(b[bl]-'0'); fi+=carr;
            if(al==0 && al==bl)  { res=to_string(fi)+res; break;}
            if(fi>9)
            {
            addi = fi%10;
            carr = fi/10;
            }
            else { addi=fi; carr=0;}
            res=to_string(addi)+res;
            bl--; al--;
        }
        for(int i=0; i<add;i++)
        {
            if(i==0) res = to_string(carr)+res;
            else res= "0"+res;
        }
        cout<<res<<'\n';
    }
    return 0;
}
