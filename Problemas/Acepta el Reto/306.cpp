#include <bits/stdc++.h>
#define MOD  46337
using namespace std;


void multiply(long long int F[2][2], long long int M[2][2])
{
  int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
  int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
  int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
  int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power(long long int F[2][2], int n)
{
  if( n == 0 || n == 1) return;
  long long int M[2][2] = {{1,1},{1,0}};
  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0) return 0;
  power(F, n-1);
  return F[0][0];
}

int main()
{
    long long int n;
    while(scanf("%lld",&n)==1 && n!=0)
    {
        printf("%d\n",fib(n));
    }
    return 0;
}
