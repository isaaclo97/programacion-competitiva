#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define MAX_N 105
#define MOD 46337
using namespace std;

typedef long long ll;

ll combi[MAX_N+2][MAX_N+2]; //aCb = combi[a][b]
void makeCombiMod(){
  rep(i, 0, MAX_N+1) combi[i][0] = 1;
  rep(i, 1, MAX_N+1) combi[0][i] = 0;
  rep(i, 1, MAX_N+1){
    rep(j, 1, i+1) combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % MOD;
  }
}

// a x + b y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y) {
  int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
// 1/a mod m
int mod_inverse(int a){
  int x, y;
  extgcd(a, MOD, x, y);
  return (MOD + x % MOD) % MOD;
}

ll B[MAX_N+2];
void initBernoulliMod(){
  makeCombiMod();
  Rep(i, MAX_N+1){
    if(i % 2) B[i] = 0;
    else B[i] = -INF;
  }
  B[0] = 1;
  B[1] = -mod_inverse(2) + MOD;
}

int BernoulliMod(int n){
  if(B[n] == -INF){
    ll sum = (1 + combi[n+1][1] * B[1]) % MOD;
    for(int i = 2; i < n; i+= 2) sum = (sum + (combi[n+1][i] * BernoulliMod(i) % MOD)) % MOD;
    B[n] = sum * mod_inverse(n+1) % MOD;
    B[n] *= -1;
    while(B[n] < 0) B[n] += MOD;
  }
  return B[n];
}

//n**p % m
int powMod(ll n, int p){
  ll ans = 1, ln = n % MOD;
  if(p <= 0) return 1;
  while(p != 0){
    if((p & 1) == 1) ans = (ans*ln) % MOD;
    ln = (ln * ln) % MOD;
    p = p >> 1;
  }
  return (int)ans;
}

//Faulhaber's formula
//S(k, n) = 1^k + 2^k + .. + n^k
int faulhaberMod(int k, ll n){
  ll ans = 0;
  Rep(j, k+1){
    if(j % 2) ans = (ans - ((combi[k+1][j] * BernoulliMod(j) % MOD) * powMod(n, k+1-j) % MOD) + MOD) % MOD;
    else ans = (ans + ((combi[k+1][j] * BernoulliMod(j) % MOD) * powMod(n, k+1-j) % MOD)) % MOD;
  }
  ans = ans * mod_inverse(k+1) % MOD;
  return (int)ans;
}

int main() {
    initBernoulliMod();
    int N,K;
    while(scanf("%d%d", &N, &K)==2 && (N!=0 || K!=0))
    {
        printf("%d\n", faulhaberMod(K, N));
    }
  return 0;
}
