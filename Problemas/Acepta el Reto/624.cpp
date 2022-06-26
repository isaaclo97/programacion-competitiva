
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        map<int,int> M;
        int value,res=0,finalRes=0;
        for(int i=0; i<n;i++){
            scanf("%d",&value);
            M[value]++;
            if(M[value]%2!=0) res++;
            else res--;
            finalRes = max(res,finalRes);
        }
        printf("%d\n",finalRes);
    }
    return 0;
}
