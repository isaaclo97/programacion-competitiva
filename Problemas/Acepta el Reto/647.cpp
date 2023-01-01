#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        int res = 0,finalRes=0;
        map<int,int> M;
        int curPos = 0;
        for(int i=0; i<n;i++){
            int cap; scanf("%d",&cap);
            if(M[cap]!=0 && M[cap]>curPos) {
                res=i-M[cap];
                curPos = M[cap];
            }
            res++;
            finalRes=max(res,finalRes);
            M[cap]=i+1;
        }
        printf("%d\n",finalRes);
    }
    return 0;
}