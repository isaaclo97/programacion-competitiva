
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    map<string,int> M;
    int total=0;
    while(cases--){
        string s; cin>>s;
        M[s]++;
        total++;
    }
    int flag=0;
    for(auto m:M){
        if(m.second>(total-m.second)) { cout<<m.first<<endl; flag=1; break;}
    }
    if(flag==0) printf("NONE\n");
    return 0;
}
