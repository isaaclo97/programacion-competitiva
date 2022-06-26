#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int da,db;
    scanf("%lld %lld",&da,&db);
    if(db>=da+2 || (da>db && (da!=9 || db!=1)) || (db==0 && da==0) ) printf("-1\n");
    else if(db!=da) {
        if(!(da!=9 && db!=1)) printf("9 10\n");
        else printf("%lld %lld\n",da,db);
    }
    else printf("%lld %lld\n",db*10,db*10+1);
    return 0;
}