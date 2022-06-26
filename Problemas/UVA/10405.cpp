#include<bits/stdc++.h>
using namespace std;
string X;
string Y;
int memo[1005][1005];
bool mark[1005][1005];
int lcs(int m, int n )
{
   if (m == 0 || n == 0) return 0;
   int &best= memo[m][n];
   if(mark[m][n]) return best;
   mark[m][n]=true;
   if (X[m-1] == Y[n-1])  return best=1+lcs(m-1, n-1);
   return best=max(lcs(m, n-1),lcs(m-1, n));
}
int main()
{
  while(getline(cin,X))
  {
      memset(mark,false,sizeof(mark));
      memset(memo,0,sizeof(memo));
  getline(cin,Y);
  printf("%d\n", lcs(X.length(),Y.length()));
  }
  return 0;
}
