#include <bits/stdc++.h>
#define lli long long int
 
using namespace std;
 
string cad;
int memo[6005][30];
bool mark[6005][30];
 
int  DP(int id,int prev){
    if(prev>26 || prev==0) return 0;
    if(id==cad.length()) return 1;
    int &best = memo[id][prev];
    if(mark[id][prev]) return best;
    mark[id][prev]=true;
    return best = DP( id + 1 , cad[id] - 48 ) + DP( id + 1 , prev * 10 + (cad[id] - 48) );
}
 
int main(){
    cin>>cad;
    while(cad!="0"){
           memset( memo , -1 ,sizeof(memo) );
           memset( mark , false ,sizeof(mark) );
        cout<<DP( 1 , cad[0] - 48 )<<'\n';
        cin>>cad;
    }
    return 0;
}
