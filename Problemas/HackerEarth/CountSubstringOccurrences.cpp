#include <bits/stdc++.h>
using namespace std;

vector<int> Z(string &s) {
int n = s.size();
int L, R;
L = R = 0;
vector<int> Z(n, 0);
for (int i = 1; i < n; ++i){
if (i < R) Z[i] = min(Z[i-L], R-i);
else Z[i] = 0;
while (Z[i] + i < n and s[Z[i]] == s[i+Z[i]]) ++Z[i];
if (i+Z[i] > R){
L = i;
R = i + Z[i];
}
}
return Z;
}

int main()
{
   string a,b; cin>>a>>b;
   string resu = a+"$"+b;
   vector<int> res = Z(resu);
   int sol = 0;
   for(unsigned int i=0; i<res.size();i++) if(res[i]==a.length()) sol++;
   printf("%d",sol);
   return 0;
}
