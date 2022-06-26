
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        int s[n],f[n];
        int time = 0;
        for(int i=0; i<n;i++) scanf("%d",&s[i]);
        for(int i=0; i<n;i++) scanf("%d",&f[i]);
        for(int i=0; i<n;i++){
            if(i==0){
                time = f[i];
                printf("%d",f[i]-s[i]);
            } else{
                time = max(s[i],time);
                if(time>f[i]) printf(" 0");
                else printf(" %d",f[i]-time);
                time = max(f[i],time);
            }
        }
        printf("\n");
    }
    return 0;
}
