
#include <bits/stdc++.h>
using namespace std;

int postIndex;
int iN[1005],post[1005];
map<int, int> hm;
stack<int> s;


void fillPre(int inStrt, int inEnd){
    if (inStrt > inEnd)      return;
    int val = post[postIndex];
    int inIndex = hm[val];
    postIndex--;
    fillPre(inIndex + 1, inEnd);     // traverse right tree
    fillPre(inStrt, inIndex - 1); // traverse left tree
    s.push(val);
}

void printPreMain(int N){
    postIndex = N - 1;
    for (int i = 0; i < N; i++)
        hm[iN[i]] = i;
    fillPre(0, N - 1);
    bool flag = true;
    while (s.size() != 0) {
        if(flag){ flag=false;  printf("%d",s.top()); }
        else printf(" %d",s.top());
        s.pop();
    }
}

int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        for(int i=0; i<n;i++) scanf("%d",&iN[i]);
        for(int i=0; i<n;i++) scanf("%d",&post[i]);
        printPreMain(n);
        printf("\n");
    }
    return 0;
}
