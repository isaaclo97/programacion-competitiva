
#include <bits/stdc++.h>
using namespace std;

int main(){
    int C,F,N;
    while(scanf("%d %d %d",&C,&F,&N)==3 && (C!=0 || F!=0 || N!=0)){
        int rookX[N],rookY[N];
        for(int i=0; i<N;i++){ scanf("%d",&rookX[i]); scanf("%d",&rookY[i]); }
        sort(rookX,rookX+N);
        sort(rookY,rookY+N);
        printf("%d %d\n",rookX[(N-1)/2],rookY[(N-1)/2]);
    }
    return 0;
}
