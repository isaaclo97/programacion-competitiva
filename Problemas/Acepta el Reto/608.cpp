
#include <bits/stdc++.h>
using namespace std;
//4
//1 7 5 4
int main(){
    int n,res,num;
    bool flag;
    while(scanf("%d",&n)==1 && n!=0){
        res = 0;
        flag = true;
        for(int i=0; i<n;i++){
            scanf("%d",&num);
            if(num<=4 && flag) { res++; flag=false;}
            if(num>6) flag=true;
        }
        printf("%d\n",res);
    }
    return 0;
}
