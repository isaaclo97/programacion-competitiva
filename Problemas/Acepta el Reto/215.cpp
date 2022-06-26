
#include<bits/stdc++.h>
using namespace std;

int preIndex;
int in[2005];
int pre[2005];
vector<int> res;
map<int, int> hm;

void printPost(int inStrt,int inEnd){
    if (inStrt > inEnd) return;
    int inIndex = hm[pre[preIndex++]];
    printPost(inStrt, inIndex - 1); // traverse left tree
    printPost(inIndex + 1, inEnd); // traverse right tree
    res.push_back(in[inIndex]);
}

int main(){
    int elem;
    while(scanf("%d",&elem)==1 && elem!=-1){
        preIndex = 0;
        res.clear();
        hm.clear();

        int idx = 0; pre[idx]=elem;
        while(scanf("%d",&elem)==1 && elem!=-1){
            idx++; pre[idx]=elem;
        }
        idx=0;
        while(scanf("%d",&elem)==1 && elem!=-1){
            in[idx]=elem; idx++;
        }
        for (int i = 0; i < idx; i++) hm[in[i]] = i;
        printPost(0, idx - 1);
        for(int i=0; i<idx;i++){
            if(i==0) printf("%d",res[i]);
            else printf(" %d",res[i]);
        }
        printf("\n");
    }
    return 0;
}
