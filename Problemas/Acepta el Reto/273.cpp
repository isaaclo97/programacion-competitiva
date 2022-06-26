#include<bits/stdc++.h>
using namespace std;
char X[1001];
string Y;
int memo[1001][1001];
inline int lcs(int m, int n )
{
   if (m == 0 || n == 0) return 0;
   int &best= memo[m][n];
   if(memo[m][n]!=-1) return best;
   memo[m][n]=0;
   if (X[m-1] == Y[n-1])  return best=1+lcs(m-1, n-1);
   return best=max(lcs(m, n-1),lcs(m-1, n));
}
int main()
{
  while(scanf("%s",X)!=EOF)
  {
      cin>>Y;
      int r =max(Y.length(),strlen(X));
      for(int i=0; i<=r;i++)
           for(int j=0; j<=r;j++)
          memo[i][j]=-1;
 cout<<lcs(strlen(X),Y.length())<<endl;
  }
  return 0;
}
