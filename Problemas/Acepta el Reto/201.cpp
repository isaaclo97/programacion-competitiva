
#include <bits/stdc++.h>
using namespace std;

string line;
bool one,two;
int idx;

int solve(){
 idx++;
 if(line[idx]=='.') return 0;
 int res = solve() + solve();
 if(res==1) two=false;
 if(res==2) one=false;
 return 1;
}

int main(){
    while(getline(cin,line)){
      if(line[0]=='.' && line.length()==1) break;
      one = two = true;
      idx = -1;
      solve();
      if(one && two) printf("12\n");
      else if(one) printf("1\n");
      else if(two) printf("2\n");
      else printf("N\n");
    }
    return 0;
}
