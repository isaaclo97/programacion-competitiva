#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    stack<int> S; int arr[cases];
    vector<int> R;
    for(int i=0;i<cases;i++) scanf("%d",&arr[i]);
    sort(arr,arr+cases);
    for(int i=0;i<cases;i++){
        if((R.size() != 0 && arr[i]==R[R.size()-1]) && (S.size()==0 || S.top()!=arr[i])) S.push(arr[i]);
        else if((R.size()==0 || arr[i]!=R[R.size()-1])) R.push_back(arr[i]);
        else break;
    }
    if(R.size()+S.size()!=cases) printf("NO\n");
    else {
        printf("YES\n%d\n",R.size());
        for(unsigned int i=0; i<R.size();i++) if(i==0) printf("%d",R[i]); else printf(" %d",R[i]);
        if(R.size()==0) printf("\n");
        printf("\n");
        printf("%d\n",S.size());
        int flag = 1;
        int aux = S.size();
        while(!S.empty()) { int e = S.top(); S.pop(); if(flag==1) {flag=0; printf("%d",e);} else printf(" %d",e); }
        if(aux==0) printf("\n");
    }
    return 0;
}
