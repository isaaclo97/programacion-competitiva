#include <bits/stdc++.h>
using namespace std;

int main(){
    int year,endyear;
    while(scanf("%d %d",&year,&endyear)==2){
        string yearN = to_string(year);
        year=yearN[yearN.length()-1]-'0';
        if((endyear-year+1)%10==0) printf("FELIZ DECADA NUEVA\n");
        else printf("TOCA ESPERAR\n");
    }
    return 0;
}
