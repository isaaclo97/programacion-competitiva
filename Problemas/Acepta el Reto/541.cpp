#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
while (b > 0) {
int temp = b; b = a % b; a = temp; }
return a; }
int lcm(int a, int b){ return a*(b/gcd(a,b));}

int main(){
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3 && (a!=0 || b!=0 || c!=0)){
        int res = gcd(a,b); res=gcd(res,c);
        printf("%d\n",a/res+b/res+c/res);
    }
    return 0;
}
