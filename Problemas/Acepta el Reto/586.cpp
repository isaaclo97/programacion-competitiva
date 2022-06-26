
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases); cin.ignore();
    while(cases--){
        int numbers; scanf("%d",&numbers);
        int arr[numbers];
        for(int i=0; i<numbers;i++) scanf("%d",&arr[i]);
        sort(arr,arr+numbers);
        int res = 0;
        for(int i=1; i<numbers;i++) if((arr[i-1]+1)!=arr[i]) res+=(arr[i]-arr[i-1])-1;
        printf("%d\n",res);
    }
    return 0;
}
