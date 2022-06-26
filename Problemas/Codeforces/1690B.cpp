
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cases; int n;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n); int a1[n],b1[n];
        for(int i=0; i<n;i++) scanf("%d",&a1[i]);
        int diff = 0;
        for(int i=0; i<n;i++) {
            scanf("%d",&b1[i]);
            if(b1[i]==0) diff=max(diff,a1[i]);
            else diff=max(diff,a1[i]-b1[i]);
        }
        bool flag = true;
        for(int i=0; i<n;i++) {
            if(b1[i]==0 && diff<a1[i]) flag = false;
            if(b1[i]!=0 && diff!=(a1[i]-b1[i])) flag=false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
