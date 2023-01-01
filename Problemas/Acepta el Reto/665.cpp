#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b, int c, int d, int e, int f){
    return a==d && b==e && c==f;
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n1,n2,n3; scanf("%d.%d.%d",&n1,&n2,&n3);
        int s1=n1,s2=n2,s3 = n3+1;
        int s11=n1,s21=n2+1,s31=0;
        int s111=n1+1,s211=0,s311=0;
        int m1,m2,m3; scanf("%d.%d.%d",&m1,&m2,&m3);
        if(compare(m1,m2,m3,s1,s2,s3) || compare(m1,m2,m3,s11,s21,s31) || compare(m1,m2,m3,s111,s211,s311)) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}