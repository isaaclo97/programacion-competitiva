
#include <bits/stdc++.h>
using namespace std;

struct ascensor{
    int baja,alta,nivel;
};

vector<ascensor> V;

bool isPosible(int level, int objetivo) {
    int planta = 0;
    for (auto ascensor: V)
        if (ascensor.nivel <= level && planta >= ascensor.baja)
            planta = max(planta, ascensor.alta);
    return planta == objetivo;
}
bool compare(ascensor a, ascensor b){
    return a.alta<b.alta;
}
int main(){
    int N;
    while(scanf("%d",&N)==1){
        int maxPlanta = 0,maxLevel=0;
        V.clear();
        for(int i=0; i<N;i++){
            int baja,alta,nivel; scanf("%d %d %d",&baja,&alta,&nivel);
            maxPlanta = max(maxPlanta,alta);
            maxLevel = max(maxLevel,nivel);
            V.push_back({baja,alta,nivel});
        }
        sort(V.begin(),V.end(),compare);
        int first = 0;
        int last = maxLevel;
        while (last - first > 1) {
            int level = (first + last) / 2;
            if (isPosible(level,maxPlanta)) last = level;
            else first = level;
        }
        printf("%d\n", last);
    }
    return 0;
}
