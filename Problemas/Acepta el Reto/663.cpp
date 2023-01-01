#include <bits/stdc++.h>
using namespace std;

int main(){
    int year,cases; scanf("%d",&cases);
    while(cases--){
        scanf("%d",&year);
        if(year>0) printf("%d\n",year-1);
        else printf("%d\n",year);
    }
    return 0;
}