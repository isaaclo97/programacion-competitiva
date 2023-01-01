#include <bits/stdc++.h>
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};
int mapa[105][105];
bool visited[105][105];
int F,C;

struct celda{
    int x,y,altura;
    bool operator<(const celda &other)const{ return altura > other.altura; } };

void bfs(int a,int b){
    priority_queue<celda> pq;
    int totalCeldas = F*C;
    int mitadCeldas = totalCeldas/2+1; //más de la mitad
    int total = 0;
    int altura = 0;
    pq.push({a,b,mapa[a][b]});
    for(int alt=0; alt<1005;alt++) {
        altura = alt;
        while (!pq.empty()) {
            celda aux = pq.top();
            if(aux.altura>altura)
                break;
            total++;
            pq.pop();
            a = aux.x;
            b = aux.y;
            visited[a][b] = true;
            for (int i = 0; i < 4; i++) {
                int I = a + sx[i];
                int J = b + sy[i];
                if (I >= 0 && I < F && J >= 0 && J < C && !visited[I][J]) {
                    visited[I][J] = true;
                    pq.push({I, J, mapa[I][J]});
                }
            }
        }
        if(total>=mitadCeldas)
            break;
    }
    printf("%d %d\n",altura,total);
}

int main(){
    while(scanf("%d %d",&C,&F)==2) {
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &mapa[i][j]);
                visited[i][j] = false;
            }
        }
        int mitad = F/2; //0 sería 0, 3 sería 1, 5 sería 2
        bfs(mitad,0);
    }
    return 0;
}