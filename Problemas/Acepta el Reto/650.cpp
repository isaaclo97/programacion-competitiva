#include <bits/stdc++.h>
using namespace std;

int main(){
    int books;
    while(scanf("%d",&books)==1){
        int b[books];
        for(int i=0; i<books;i++) scanf("%d",&b[i]);
        sort(b,b+books, greater<int>());
        long long int descuento = 0;
        for(int i=1; i<=books;i++) if(i%3==0) descuento+=b[i-1];
        printf("%lld\n",descuento);
    }
    return 0;
}