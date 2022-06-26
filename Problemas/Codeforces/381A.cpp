/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 11:46:56
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    int j=n-1;
    int f=0,resA,resB; resA=resB=0;
    for(int i=0; i<n;i++){
        if(arr[f]>arr[j]){
            if(i%2==0) resA+=arr[f];
            else resB+=arr[f];
            f++;
        }
        else{
            if(i%2==0) resA+=arr[j];
            else resB+=arr[j];
            j--;
        }
    }
    printf("%d %d",resA,resB);
    return 0;
}
