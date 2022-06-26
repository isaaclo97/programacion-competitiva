#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,cases; scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&n,&a); a--;
        int total=0;
        int arr[n];
        for(int i=0; i<n;i++) scanf("%d",&arr[i]);
        for(int i=0; i<n;i++){
            if(i<a) total+=min(arr[i],arr[a])*2;
            else if(i==a) total+=arr[a]*2;
            else if(i>a) total+=min(arr[i],arr[a]-1)*2;
        }
        printf("%d\n",total);
    }
    return 0;
}
