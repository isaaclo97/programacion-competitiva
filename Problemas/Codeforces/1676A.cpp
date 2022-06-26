
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cases; scanf("%d",&cases);
    while(cases--) {
        string n; cin>>n;
        if(n[0]+n[1]+n[2] == n[3]+n[4]+n[5]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
