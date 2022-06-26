
#include <bits/stdc++.h>
using namespace std;

int main(){
    int tren,anden;
    while(scanf("%d %d",&tren,&anden)==2 && (tren!=0 || anden!=0)){
        long long int leftAcum[anden+1], rightAcum[anden+1], andenPasarejos[anden];
        leftAcum[0]=0; rightAcum[anden]=0;
        for(int i=0; i<anden;i++){
            scanf("%lld",&andenPasarejos[i]);
            leftAcum[i+1]=leftAcum[i]*2+andenPasarejos[i];
        }
        for(int i=anden-1; i>=0;i--){
            rightAcum[i]=rightAcum[i+1]*2+andenPasarejos[i];
        }
        long long int res = -1;
        for(int i=0; i<anden;i++){
            long long int totalDistLeft = leftAcum[i];
            long long int totalDistRight = rightAcum[i+tren];
            if(res==-1) res=totalDistLeft+totalDistRight;
            res = min(res,totalDistLeft+totalDistRight);
        }
        printf("%lld\n",res);
    }
    return 0;
}
