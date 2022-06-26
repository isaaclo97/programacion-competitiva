
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n,k; scanf("%d %d",&n,&k);
        string line; cin>>line;
        int res = 0,finalRes=0;
        for(int i=0; i<k;i++){
            if(line[i]=='W') res++;
        }
        finalRes = res;
        for(int i=k; i<line.length();i++){
            if(line[i-k]=='W') res--;
            if(line[i]=='W') res++;
            finalRes = min(finalRes,res);
        }
        printf("%d\n",finalRes);
    }
    return 0;
}
