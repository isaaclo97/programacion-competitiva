#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)

void manacher(int n, char *str, int *r) {
r[0] = 0;
int p = 0;
FOR(i, 1, 2*n-1) {
r[i] = (p/2 + r[p] >= (i+1)/2) ? min(r[2*p - i], p/2 + r[p]
- i/2) : 0;
while (i/2 + r[i] + 1 < n && (i+1)/2 - r[i] - 1 >= 0
&& str[i/2 + r[i] + 1] == str[(i+1)/2 - r[i] - 1]) r[i]++;
if (i/2 + r[i] > p/2 + r[p]) p = i;
}
 FOR(i,0,2*n-1) r[i] = r[i]*2 + !(i&1); // change radius to diameter
 int sol = 0;
 for(int i=0; i<2*n-1;i++) sol=max(r[i],sol);
 printf("%d\n",sol);
}

int main()
{
    int n; char s[100005];
    scanf("%d",&n); scanf("%s",s);
    int arr[n*2-1]; memset(arr,0,sizeof(arr));
    manacher(n,s,arr);
    return 0;
}
