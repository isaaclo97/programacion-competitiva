
#include <bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0){
        int arr[cases];
        for(int i=0; i<cases;i++) scanf("%d",&arr[i]);
        sort(arr,arr+cases);
        int res = -0x3f3f3f3f;
        for(int i=0;i<cases;i+=2) res=max(res,abs(arr[i]-arr[i+1]));
        printf("%d\n",res);
    }
    return 0;
}
