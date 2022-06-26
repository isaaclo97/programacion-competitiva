
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    set<int> S;
    for(int i=0; i<cases;i++){
        string num; cin>>num;
        if(num[0]=='-' || num.length()>8) continue;
        S.insert(stoi(num));
    }
    set<int>::iterator it = S.begin();
    int flag = 0,last=0;
    while (it != S.end())
    {
        if(*it==last) { it++; last++; continue; }
        else { flag=2; printf("%d\n",last); break;}
        it++;
    }
    if(flag==0) printf("%d\n",last);
    return 0;
}
