
#include <bits/stdc++.h>
using namespace std;

vector<int> V;
int find(int searched){
    int first = 0, middle, last = V.size() -1;
    while (first<=last) {
        middle = (first + last) / 2;
        if (searched == V[middle]) return middle;
        else {
            if (V[middle] > searched) last = middle - 1;
            else first = middle + 1;
        }
    }
    return first;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n!=0||m!=0)){
       int dragon[n];
       for(int i=0; i<n;i++) scanf("%d",&dragon[i]);
       for(int i=0; i<m;i++) { int aux; scanf("%d",&aux); V.push_back(aux); }
       sort(V.begin(),V.end());
       int res = 0;
       bool solution=true;
       for(int i=0; i<n && solution;i++){
           int index = find(dragon[i]);
           if(index==(int)V.size()) { solution=false; continue;}
           else res+=V[index];
           V.erase(V.begin()+index);
       }
       if(!solution) printf("Loowater is doomed!\n");
       else printf("%d\n",res);
       V.clear();
    }
    return 0;
}
