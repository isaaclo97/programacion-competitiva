
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0){
        string name;
        map<string,int> counter;
        for(int i=0; i<cases;i++){
            cin>>name; counter[name]++;

        }
        int completos=0, incompletos=0, restantes=0;
        map<string,int> visited;
        for(auto c:counter){
            string macho = c.first; macho[macho.length()-1]='o';
            string hembra = c.first; hembra[hembra.length()-1]='a';
            if(visited[macho]==1 || visited[hembra]==1) continue;
            visited[macho]=visited[hembra]=1;
            if(counter[macho]>=1 && counter[hembra]>=1) completos++;
            if(counter[macho]==0 || counter[hembra]==0) incompletos++;
            if(counter[macho]>1) restantes+=counter[macho]-1;
            if(counter[hembra]>1) restantes+=counter[hembra]-1;
        }
        printf("%d %d %d\n",completos,incompletos,restantes);
    }
}
