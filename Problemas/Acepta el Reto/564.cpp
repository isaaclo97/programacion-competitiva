
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases,k; scanf("%d",&cases);
    while(cases--){
       scanf("%d",&k);
       printf("%d\n",k/3);
    }
    return 0;
}
/*
2^1 = 2 - 1 = 1
2^2 = 4 - 1 = 3
2^3 = 8 - 1 = 7 % 7 = 0
2^4 = 16 - 1 = 15
2^5 = 32 - 1 = 31
2^6 = 64 - 1 = 63 % 7 = 0
2^7 = 127 - 1 = 126
2^8 = 256 - 1 = 255
2^9 = 512 - 1 = 511%7 = 0
2^10 = 1024 - 1 = 1023
*/
