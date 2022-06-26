#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases; scanf("%d", &cases);
    while(cases--) {
        int fPX,fPY,sPX,sPY;
        scanf("%d %d %d %d",&fPX,&fPY,&sPX,&sPY);
        int minF = min(fPX,fPY);
        int maxF = max(fPX,fPY);
        int minS = min(sPX,sPY);
        int maxS = max(sPX,sPY);
        if(minS <= minF && maxS > minF) printf("SOLAPADOS\n"); //10 20 10 30 o 10 20 19 30
        else if((minF < minS && minS < maxF) && maxS > minF) printf("SOLAPADOS\n"); // 10 30 20 40
        else printf("SEPARADOS\n");
    }
    return 0;
}
