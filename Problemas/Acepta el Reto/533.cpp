
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        long long int kilos; scanf("%lld",&kilos); kilos*=8;
        long long int flag=0,total=0,num,index=1;
        while(scanf("%lld",&num)==1 && num!=0){
            total+=num;
            if(kilos<=total && flag==0) { flag=1; printf("%lld\n",index);}
            index++;
        }
        if(flag==0) printf("SIGAMOS RECICLANDO\n");
    }
    return 0;
}
