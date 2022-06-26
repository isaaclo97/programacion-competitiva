
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        string line; cin>>line;
        long long int res=0;
        int acu = 1;
        for(int i=0; i<line.length();i++){
            if(line[i]=='O'){ res+=acu*10; acu++; }
            else acu=1;
        }
        printf("%lld\n",res);
    }
}
