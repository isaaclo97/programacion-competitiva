#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int total=0;
        string line; cin>>line;
        for(unsigned int i=0; i<line.length();i++){
            if(line[i]=='.'){ total++; i+=2; }
        }
        printf("%d\n",total);
    }
    return 0;
}
