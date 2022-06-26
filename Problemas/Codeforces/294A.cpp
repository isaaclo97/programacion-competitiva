/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 19:26:45
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n,n2; scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&n2);
    for(int i=0; i<n2;i++){
        int bird,line;
        scanf("%d %d",&line,&bird);
        if(line==n){
            arr[line-2]+=bird-1;
        }
        else{
            arr[line]+=arr[line-1]-bird;
            arr[line-2]+=bird-1;
        }
        arr[line-1]=0;
    }
    for(int i=0; i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
