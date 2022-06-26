#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,add=0; scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d",&m);
        if(m==0) printf("0\n");
        else if(m%2!=0) {
            if(m<0) add++;
            if(m>0) add--;
            if(add==-2 || add==2 ) { printf("%d\n",m/2-(add/2)); add=0;}
            else printf("%d\n",m/2);

        }
        else printf("%d\n",m/2);
    }
    return 0;
}
