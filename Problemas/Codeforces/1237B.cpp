#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,aux,res=0,j=0; scanf("%d",&n);
    vector<int> V,V2;
    for(int i=0; i<n;i++){
        scanf("%d",&aux);
        V.push_back(aux);
    }
    for(int i=0; i<n;i++){
        scanf("%d",&aux);
        V2.push_back(aux);
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    for(int i=0; i<n && j<n;i++){
        if(visited[V[i]]) continue;
        while(V[i]!=V2[j]) {
            visited[V2[j]]=true;
            //cout<<V2[j]<<endl;
            j++; res++;
        }
        j++;
        visited[V[i]]=true;
    }
    printf("%d\n",res);
    return 0;
}