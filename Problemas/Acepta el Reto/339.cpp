
#include <bits/stdc++.h>
using namespace std;

int dias[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool checkDates(int d,int m,int y, int d1, int m1, int y1){
    if(y<y1) return true;
    else if(y==y1 && m<m1) return true;
    else if(y==y1 && m==m1 && d<=d1) return true;
    return false;
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int d,m,y;
        scanf("%d %d %d",&d,&m,&y);
        if(checkDates(d,m,y,4,10,1582) || checkDates(14,9,1752,d,m,y)){
            printf("%d %d %d\n",d,m,y);
            continue;
        }
        else{
            d-=10;
            if(checkDates(29,2,1700,d,m,y)) d--;
            if(d<1 && m!=1){
                m-=1;
                if(!(y%4)){
                    d+=dias[m];
                    if(m==2) d++;
                }
                else d+=dias[m];
            }
            else if(d<1){
                y--;  m=12; d+=31;
            }
        }
        printf("%d %d %d\n",d,m,y);
    }
    return 0;
}
