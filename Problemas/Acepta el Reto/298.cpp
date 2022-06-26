
#include <bits/stdc++.h>
using namespace std;

bool res;

void solve(int min, int max){
 int value;
 scanf("%d",&value);
 if(value==-1) return ;
   if (value<min || value>max)
       res = false;
   solve(min, value-1);
   solve(value+1, max);
}

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
      res = true;
      solve(-0x3f3f3f,0x3f3f3f);
      if(res) printf("SI\n");
      else printf("NO\n");
    }
    return 0;
}
