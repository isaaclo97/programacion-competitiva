
#include <bits/stdc++.h>
using namespace std;

int main(){
    int palos;
    while(scanf("%d",&palos)==1 && palos!=0){
        int num; string p;
        bool win = true;
        map<string,int> M; M["B"]=0; M["E"]=0; M["O"]=0; M["C"]=0;
        queue<pair<string,int>> Q;
        for(int i=0; i<palos*10;i++){
            cin>>num>>p;
            if(num==10) num=8;
            if(num==11) num=9;
            if(num==12) num=10;
            Q.push({p,num});
        }
        while(Q.size()!=0){
            stack<pair<string,int>> S;
            int currentSize = Q.size();
            while(Q.size()!=0){
                pair<string,int> first = Q.front(); Q.pop(); S.push(first);
                if(Q.size()!=0) {
                    pair<string,int> second = Q.front(); Q.pop(); S.push(second);
                }
                while(!S.empty() && M[S.top().first]+1==S.top().second){
                    M[S.top().first]++;
                    S.pop();
                }
            }
            if(currentSize==S.size()) {
                win=false;
                break;
            }
            vector<pair<string,int>> V;
            while(S.size()!=0){
                pair<string,int> first = S.top(); S.pop(); V.push_back(first);
                if(S.size()!=0) {
                    pair<string,int> second = S.top(); S.pop(); V.push_back(second);
                }
            }
            for(int i=V.size()-1;i>=0; i--) Q.push(V[i]);
        }
        if(win) printf("GANA\n");
        else printf("PIERDE\n");
    }
    return 0;
}
