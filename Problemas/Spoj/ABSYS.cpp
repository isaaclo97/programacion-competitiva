#include<bits/stdc++.h>
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define rep(i,n) FOR(i,0,n-1)
using namespace std;
typedef long long ll;
bool check(string s){
    ll i=0;
    rep(i,s.size()){
        if(isalpha(s[i])) return false;
    }
    return true;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        string a,b,c;
        char plus,equal;
        cin>>a>>plus>>b>>equal>>c;
        ll A=-1,B=-1,C=-1;
        if(check(a)) A=atol(a.c_str());
        if(check(b)) B=atol(b.c_str());
        if(check(c)) C=atol(c.c_str());
        if(A == -1) {
            A = C-B;
        }
        else if(B == -1){
            B = C-A;
        }
        else C = A+B;
        cout<<A<<" + "<<B<<" = "<<C<<endl;
    }
    return 0;
} 
