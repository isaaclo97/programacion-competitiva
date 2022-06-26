
#include <bits/stdc++.h>
using namespace std;

int main(){
   int cases;
   while(scanf("%d",&cases)==1 && cases!=0){
        int X[cases],Y[cases];
        for(int i=0; i<cases;i++) scanf("%d %d",&X[i],&Y[i]);
        int res = 0;
        for(int i=0; i<cases;i++)
            for(int j=i+1; j<cases;j++){
                res = max(res, abs(X[i]-X[j])+abs(Y[i]-Y[j])); //Manhattan
            }
        printf("%d\n",res);
   }
   return 0;
}
