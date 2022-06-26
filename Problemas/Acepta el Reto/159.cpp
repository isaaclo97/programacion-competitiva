
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, min, h1, min1, digit, cont;
    while(scanf("%d:%d %d:%d %d", &h, &min, &h1, &min1, &digit)==5 && h!=24){
        cont=0;
        while(h<=h1 && !(h==h1&&min>min1)){
            if(h%10==digit||h/10==digit||min%10==digit||min/10==digit) cont++;
            min++;
            if(min==60){min=0;h++;}
        }
        printf("%d\n", cont);
    }
    return 0;
}
