#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n!=0 || m!=0)){
        if(n>=m) printf("CUERDO\n");
        else printf("SENIL\n");
    }
    return 0;
}
