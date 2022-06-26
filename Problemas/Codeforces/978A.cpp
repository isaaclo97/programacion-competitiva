#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
        int cases; cin>>cases;
        map<int,int> M;
        map<int,int> Ma;
        for(int i=0; i<cases;i++) {int au; cin>>au; M[au]=i;}
        int flag=1;
        for(auto m:M) Ma[m.second]=m.first;
        cout<<M.size()<<endl;
        for(auto m:Ma) if(flag==1){flag=0; cout<<m.second;} else cout<<" "<<m.second;
    return 0;
}
