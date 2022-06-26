#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int arr[3],arr1[3]; scanf("%d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr1[0],&arr1[1],&arr1[2]);
        sort(arr,arr+3);
        sort(arr1,arr1+3);
        if(arr[0]<arr1[0] && arr[1]<arr1[1] && arr[2]<arr1[2]) printf("SIRVE\n");
        else printf("NO SIRVE\n");
    }
    return 0;
}
