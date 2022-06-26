
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0){
        int res[cases],paro[cases]; memset(res,0,sizeof(res));
        for(int i=0; i<cases;i++){
            scanf("%d",&paro[i]);
            int j = i - 1;
            while (j >= 0 && paro[i] < paro[j]) {
                res[i] += res[j] + 1;
                j -= (res[j] + 1);
            }
        }
        for(int i=0; i<cases;i++) if(i==0) printf("%d",res[i]); else printf(" %d",res[i]);
        printf("\n");
    }
    return 0;
}
