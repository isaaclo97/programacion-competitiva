
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--) {
        int n; cin>>n;
        int res[n+5],last,current,lastIndex=1;
        int numEquals = 0;
        bool valid = true;
        scanf("%d",&last);
        if(n==1) valid=false;
        for(int i=1; i<n;i++){
            scanf("%d",&current);
            if(current==last){
                numEquals++;
                res[i-1]=i+1;
            }
            else if(numEquals==0) valid=false;
            else {
                last=current;
                res[i-1]=lastIndex;
                lastIndex=i+1;
                numEquals=0;
            }
            if(current==last && i+1==n && numEquals!=0){
                res[i]=lastIndex;
            }
            if(current==last && i+1==n && numEquals==0) valid=false;
        }
        if(valid){
            for(int i=0; i<n;i++) {
                if(i==0) printf("%d",res[i]);
                else printf(" %d",res[i]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
