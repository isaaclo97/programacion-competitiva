
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d",&N)==1){
        int arrAcu[N];
        int acu = 0,read;
        for(int i=0; i<N;i++) { scanf("%d",&read); acu+=read; arrAcu[i]=acu; }
        int minimo = 0x3f3f3f3f;
        int flag=1;
        int index,l,r,lfinal,rfinal;
        for(int i=0; i<N;i++) {
            l=arrAcu[i];
            r=abs(acu-arrAcu[i]);
            if(abs(l-r)<minimo) {minimo=abs(l-r); index=i; lfinal=l; rfinal=r; flag=1;}
            else if(abs(l-r)==minimo) flag=0;
        }
        if(flag==0) printf("NO JUEGAN\n");
        else printf("%d %d %d\n",index+1,lfinal,rfinal);
    }
    return 0;
}
