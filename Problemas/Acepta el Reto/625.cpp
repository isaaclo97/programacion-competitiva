
#include <bits/stdc++.h>
using namespace std;
// teorema de la desigualdad del triángulo.
int isPossible(int a, int b, int c){
    if((a+b>c) && (a+c>b) && (c+b>a))
        return a+b+c;
    return -1;
}
bool compare(int a, int b){
    return a>b;
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n, res = -1,cnt=0; scanf("%d",&n); int arr[n];
        map<int,int> M;
        map<pair<int,int>,int> M1;
        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        sort(arr,arr+n,compare);
        for(int i=0; i<n; i++) {
            if(M[arr[i]]==1) continue; //si ya se ha tenido este valor, todos sus trios han sido calculados
            M[arr[i]] = 1;
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if((arr[i]+arr[j]+arr[k])<res) break;
                    //cnt++;
                    //printf("%d %d %d\n",arr[i],arr[j],arr[k]);
                    int check = isPossible(arr[i],arr[j],arr[k]);
                    res = max(res, check);
                }
            }
        }
        //printf("Total iterations %d\n",cnt);
        if(res==-1) printf("NO HAY NINGUNO\n");
        else printf("%d\n",res);
    }
    return 0;
}
