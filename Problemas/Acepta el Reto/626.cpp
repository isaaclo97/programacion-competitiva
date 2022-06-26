
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    for(int i=0; i<n;i++){
        int day,month,year;
        scanf("%d/%d/%d",&day,&month,&year); cin.ignore();
        if(((day<29 && month==2)|| month==1) && year%4==0)
            printf("29/02/%04d\n",year);
        else{
            if(year%4==0) year++;
            for(int i = year; i<9999;i++)
                if(i%4==0){year = i; break;}
            printf("29/02/%04d\n",year);
        }
    }
    return 0;
}
