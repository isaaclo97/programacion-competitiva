
#include <bits/stdc++.h>
using namespace std;

struct node{
    int inicio,final,tiempo,valor;
};

vector<node> v;
bool flag;
int hSalida, hDestino,tiempoMaximo,res;

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

inline void DFS(int start, int time, int sky){
    if(time>tiempoMaximo) return;
    if(start>=hDestino && time+(start-hDestino)<=tiempoMaximo){
        flag=true;
        res=max(res,sky+(start-hDestino));
    }
    for(int i=0;i<v.size();i++){
        if(v[i].inicio<=start){
            DFS(v[i].final,time+(start-v[i].inicio)+v[i].tiempo,sky+(start-v[i].inicio));
        }
    }
}

int main(){
    int N;
    while(scanf("%d",&N) && N!=0){
        int a,b,c;
        v.clear();
        for(int i=0; i<N;i++){
            fastInput(a); fastInput(b); fastInput(c);
            v.push_back(node{a,b,c,a-b});
        }
        res = 0;
        fastInput(hSalida); fastInput(hDestino); fastInput(tiempoMaximo);
        flag = false;
        DFS(hSalida,0,0);
        if(!flag) printf("IMPOSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
