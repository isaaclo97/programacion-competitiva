
#include <bits/stdc++.h>
using namespace std;

int fibDP (int n) {
    int f[n + 2];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int fib (int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib (n - 2) + fib (n - 1);
}

 void solve(int n, int nivel) {
    string esp="   ";
    string res="";
    for (int i = 0; i < nivel; i++) res+=esp;
    if (n == 0 || n == 1)  {
        printf("%s%d\n", res.c_str(), n);
        return;
    }
    printf("%s%d\n", res.c_str(), fib(n));
    solve (n-2, nivel+1);
    solve (n-1, nivel+1);
}

int main(){
    int n;
    while(scanf("%d",&n)==1 && n>=0){
        solve(n, 0);
        printf("====\n");
    }
    return 0;
}
