
#include <bits/stdc++.h>
using namespace std;

vector<int> tree, postOrden,preOrden;

void solve(int start, int end){
    if(start>end) return;
    int middle = (end+start+1)/2;
    preOrden.push_back(tree[middle]);
    solve(start,middle-1);
    solve(middle+1,end);
    postOrden.push_back(tree[middle]);
}

int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=-1){
        tree.clear(); postOrden.clear(); preOrden.clear();
        tree.push_back(cases);
        while(scanf("%d",&cases)==1 && cases!=-1){
            tree.push_back(cases);
        }
        solve(0,tree.size()-1);
        for(unsigned int i=0; i<preOrden.size();i++){
            if(i==0) printf("%d",preOrden[i]);
            else printf(" %d",preOrden[i]);
        }
        printf("\n");
        for(unsigned int i=0; i<postOrden.size();i++){
            if(i==0) printf("%d",postOrden[i]);
            else printf(" %d",postOrden[i]);
        }
        printf("\n");
    }
    return 0;
}
