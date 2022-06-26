
#include <bits/stdc++.h>
using namespace std;

inline void fastInput(long long int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

long long int mem[2][1005][3];
long long int L[1005];
long long int P[1005];
long long int n,l;

void Cometa(){
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= l; w++) {
            if (i == 0 || w == 0){
                mem[i % 2][w][1] = mem[i % 2][w][0] = 0x3f3f3f3f;
                mem[i % 2][w][2] = 0;
            }
            else if((L[i-1])== w){

                mem[i % 2][w][1] = min(
                        P[i - 1],
                        mem[(i - 1) % 2][w][1]);
                mem[i % 2][w][0]=1;
                mem[i % 2][w][2]=1+ mem[(i - 1) % 2][w][2];
            }
            else if (L[i - 1] < w) {
                mem[i % 2][w][0] = min( 1 + mem[(i - 1) % 2][w - L[i - 1]][0],
                        mem[(i - 1) % 2][w][0]);

                mem[i % 2][w][1] = min( P[i - 1] + mem[(i - 1) % 2][w - L[i - 1]][1],
                                        mem[(i - 1) % 2][w][1]);
                mem[i % 2][w][2] =  mem[(i - 1) % 2][w - L[i - 1]][2] + mem[(i - 1) % 2][w][2];
            }
            else {
                mem[i % 2][w][0] = mem[(i - 1) % 2][w][0];
                mem[i % 2][w][1] = mem[(i - 1) % 2][w][1];
                mem[i % 2][w][2] = mem[(i - 1) % 2][w][2];
            }
        }
    }
}

int main() {
    while(scanf("%lld",&n)==1){ fastInput(l);
        for(int i=0; i<n;i++) {fastInput(L[i]); fastInput(P[i]);}
        /*for (int i = 0; i < 2; i++)
            for (int j = 0; j <= l; j++)
                mem[i][j][0] = mem[i][j][1] = mem[i][j][2] = 0; */
        Cometa();
        if (mem[n % 2][l][2] != 0)  printf("SI %lld %lld %lld\n",mem[n % 2][l][2],mem[n % 2][l][0], mem[n % 2][l][1]);
        else printf("NO\n");
    }
}
