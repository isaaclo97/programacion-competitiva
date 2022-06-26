
#include <bits/stdc++.h>
using namespace std;

int dp[1000000];

int solve(int n){
    if(n<=2) return 0;
    if(dp[n]!=0) return dp[n];
    return dp[n]=solve((n-1)/2)+solve((n-1)-(n-1)/2)+1;
}
int main(){
    memset(dp,0,sizeof(dp));
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        if(n==1 || n==2) printf("1\n");
        else printf("%d\n",solve(n-2)+2);
    }
}
            else {
                lastI = i;
                total += V[i].end-V[i].start+1;
            }
        }
        printf("%d\n",total);
    }
}

//4 10 20 30 40 15 25 12 18 0
