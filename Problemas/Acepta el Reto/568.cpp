#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    //if (a.second != b.second)
    //    return a.second < b.second;
    //return a.first < b.first;
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
pair<int, int> a[10005];
int main(){
    int N,startx,endx,starty,endy;
    while(scanf("%d",&N)==1) {
        for(int i=0;i<N;i++) {
            scanf("%d-%d %d-%d", &startx, &endx, &starty, &endy);
            int startTime = endx*31+startx;
            int endTime = endy*31+starty;
            a[i].first = startTime;
            a[i].second = endTime;
        }
        sort(a, a + N, compare);
        int count = 0;
        priority_queue<int> pq;
        vector<int> current;
        for (int i = 0; i < N; i++) {
            pq.push(a[i].second);
            current.clear();
            while(!pq.empty()){
                current.push_back(pq.top());
                pq.pop();
            }
            for(int x : current){
                if(x < a[i].first) //si alguno acaba antes del inicial
                    count++;
                else
                    pq.push(x);
            }
            if(pq.size() > 4) //asegurar que siempre tiene 4
                pq.pop(); //quitar el que termina mas tarde
        }
        printf("%d\n",count+pq.size());
    }
    return 0;
}