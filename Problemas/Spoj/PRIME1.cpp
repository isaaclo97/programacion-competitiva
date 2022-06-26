#include <bits/stdc++.h>
using namespace std;
 
int prime(long long int x){
    if(x==1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3;i<=sqrt(x);i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
 
int main() {
  int flag=1;
  int cases; scanf("%d",&cases);
  while(cases--)
  {
      if(flag==0) printf("\n");
      long long int a,b; scanf("%lld%lld",&a,&b);
      for(long long int i=a;i<=b;i++) if(prime(i)==1) printf("%lld\n",i);
      flag=0;
  }
  return 0;
}
 
