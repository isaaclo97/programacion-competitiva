
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        if(n%2==0) printf("%d\n",n+1);
        else printf("%d\n",n-1);
    }
    return 0;
}
