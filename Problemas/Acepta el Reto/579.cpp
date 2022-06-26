
#include <bits/stdc++.h>
using namespace std;

inline int getchar_unlocked() { return getchar(); }
inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

struct node{
    int priority,duration;
};

bool compare(node a, node b){
    if(a.priority == b.priority)
        return a.duration<b.duration;
    return a.priority>b.priority;
}


int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        vector<node> V;
        for(int i=0; i<n;i++){
            int p,d; fastInput(p); fastInput(d);
            V.push_back({p,d});
        }
        sort(V.begin(),V.end(),compare);
        for(int i=0; i<n;i++){
            printf("%d %d\n",V[i].priority,V[i].duration);
        }
        printf("---\n");
    }
    return 0;
}
