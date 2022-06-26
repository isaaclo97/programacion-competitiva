
#include <bits/stdc++.h>
using namespace std;

int memo[35];
int memo2[35];
void data() {
    memo[0] = memo[1] = 1;
    memo2[0] = 1;
    memo2[1] = 2;
    int acum = 2;
    for (int i=2; i<35; i++) {
        memo[i] = (2*memo[i-2]) + memo[i-1];
        acum += memo[i];
        memo2[i]=acum;
    }
}

int main(){
    data();
    int N; scanf("%d",&N);
    while(N--){
        int num; scanf("%d",&num);
        for(int i=0; i<35;i++){
            if(memo2[i]>=num) {
              printf("%d\n",i+1);
              break;
            }
        }
    }
    return 0;
}
