#include <bits/stdc++.h>
using namespace std;

int solve2(int a, int b, int n){
    if(n%6==0) return a;
    else if(n%6==1) return b;
    else if(n%6==2) return b-a;
    else if(n%6==3) return -a;
    else if(n%6==4) return -b;
    else if(n%6==5) return a-b;
}
int main(){
    int a,b,n;
    while(scanf("%d %d %d",&a,&b,&n)==3 && (a!=0 || b!=0 || n!=0)){
        printf("%d\n",solve2(a,b,n));
    }
    return 0;
}