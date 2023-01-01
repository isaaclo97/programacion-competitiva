#include <bits/stdc++.h>
using namespace std;

//RIGHT LEFT TOP DOWN
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct snake{
    int x,y,move;
};

vector<snake> serpiente;

void move(int curMove) {
    int curMoveBueno = curMove;
    for(int j=0;j<serpiente.size();j++) {
        int nx = serpiente[j].x + dx[curMoveBueno];
        int ny = serpiente[j].y + dy[curMoveBueno];
        serpiente[j].x=nx; serpiente[j].y=ny;
        curMove = serpiente[j].move; //modificar el siguiente con el movimiento del actual
        serpiente[j].move=curMoveBueno;
        curMoveBueno = curMove;
    }
}

bool choca() {
    map<pair<int,int>,int> choca;
    for(int j=0;j<serpiente.size();j++) {
        if(choca[{serpiente[j].x,serpiente[j].y}]==1)
            return true;
        choca[{serpiente[j].x,serpiente[j].y}]=1;
        if (serpiente[j].x < 0 || serpiente[j].x >= 21 || serpiente[j].y < 0 || serpiente[j].y >= 21) { //si toca un límite la cabeza muere
            return true;
        }
    }
    return false;
}

int main(){
    int moves;
    while(scanf("%d",&moves)==1 && moves!=0){
        int totalMoves = 0,t;
        string pos;
        vector<pair<int,string>> V;
        for(int i=0; i<moves;i++){
            cin>>t>>pos; V.push_back({t,pos});
        }
        V.push_back({100000000,"R"});
        bool muerte = false;
        int curMove = 2;
        serpiente.clear();
        for(int i=0;i<10;i++){
            serpiente.push_back({10,10-i,2});
        }
        for(int i=0; i<=moves;i++){
            if(muerte) break;
            while(totalMoves!=V[i].first){
                snake addNueva;
                if(totalMoves%10==0) addNueva = serpiente[serpiente.size()-1];
                move(curMove);
                if(totalMoves%10==0 && i!=0) serpiente.push_back(addNueva);
                muerte = choca();
                if(muerte) break;
                totalMoves++;
            }
            //RIGHT LEFT TOP DOWN
            if(V[i].second=="R") curMove = 0;
            if(V[i].second=="L") curMove = 1;
            if(V[i].second=="U") curMove = 2;
            if(V[i].second=="D") curMove = 3;
        }
        printf("%d\n",totalMoves);
    }
    return 0;
}