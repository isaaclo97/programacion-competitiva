#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(scanf("%d",&num)==1 && num!=0){
        while(num!=0){
            if(num>=1000000) { printf("H"); num-=1000000; }
            else if(num>=100000){ printf("R"); num-=100000; }
            else if(num>=10000){ printf("D"); num-=10000;}
            else if(num>=1000){ printf("F"); num-=1000;}
            else if(num>=100){ printf("C"); num-=100;}
            else if(num>=10){ printf("G"); num-=10;}
            else{ printf("T"); num--;}
        }
        printf("\n");
    }
    return 0;
}