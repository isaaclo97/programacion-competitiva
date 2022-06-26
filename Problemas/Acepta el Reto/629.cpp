
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    while(scanf("%d",&cases) == 1 && (cases!=0)){
        int vecinos[cases]; int res = 0,rem=0;
        for(int i =0; i<cases;i++) scanf("%d",&vecinos[i]);
        for(int i =cases-1; i>=0;i--){
            if(rem>0) res++;
            rem = max(vecinos[i],rem-1);
        }
        printf("%d\n",res);
    }
    return 0;
}
