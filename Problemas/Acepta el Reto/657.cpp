#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,a,b,c; scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        int dist_a = abs(a - b);
        int dist_c = abs(c - b);
        if(a<0 && b>0 || b<0 && a>0) dist_a--;
        if(c<0 && b>0 || b<0 && c>0) dist_c--;
        if (dist_a < dist_c) printf("%d\n",a);
        else if (dist_c < dist_a) printf("%d\n",c);
        else  printf("EMPATE\n");
    }
    return 0;
}