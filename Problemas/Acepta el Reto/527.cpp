
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        string line; cin>>line;
        int cnt = 0;
        long long int res = 0;
        for(int i=0; i<line.length();i++){
            if(line[i]=='0') cnt++;
            else res+=line[i]-'0';
        }
        if((res%9==0 && cnt>=2) || (line=="0")) printf("COMPLETO\n");
        //El 0 es divisible por 900.
        else{
            for(int i=cnt; i<2;i++) printf("0");
            if(res%9!=0) printf("%d",9-res%9);
            printf("\n");
        }
    }
    return 0;
}
