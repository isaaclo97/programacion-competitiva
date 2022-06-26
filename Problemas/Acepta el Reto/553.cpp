
#include <bits/stdc++.h>
using namespace std;

struct state{
    int start,end;
};
bool compare(state a, state b){
    if(a.start==b.start) return a.end>b.end;
    return a.start<b.start;
}

int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0){
       vector<state> V;
        for(int i=0; i<n;i++){
            int start,end; scanf("%d %d",&start,&end);
            V.push_back({start,end});
        }
        sort(V.begin(),V.end(),compare);
        int total = V[0].end-V[0].start+1;
        int lastI = 0;
        for(int i=1; i<n;i++){
            if(V[lastI].end>=V[i].start) {
                int value = V[i].start-V[lastI].end+(V[i].end-V[i].start);
                if(value<=0) continue;
                lastI = i;
                total+=value;
            }
            else {
                lastI = i;
                total += V[i].end-V[i].start+1;
            }
        }
        printf("%d\n",total);
    }
}

//4 10 20 30 40 15 25 12 18 0
