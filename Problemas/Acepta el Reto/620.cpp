
#include <bits/stdc++.h>
using namespace std;

int size,n;
int cintas[10];

int solve(int size1, int id, int size2){
    if(size1>size || size2>size) return -0x3f3f3f; //si pasa del tamaño
    if(n==id) return 0; //ultima cinta
    return max(solve(size1+cintas[id],id+1,size2), solve(size1,id+1,size2+cintas[id]))+1;
}

int main(){
    while(scanf("%d %d",&size,&n)==2){
        for(int i=0; i<n;i++) scanf("%d",&cintas[i]);
        if(solve(0,0,0)==n) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
