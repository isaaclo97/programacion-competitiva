#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, v;// x->y, v
    int next;
} edge[50005];
int e, head[1005], dis[1005], previ[1005], record[1005];
void addEdge(int x, int y, int v) {
    edge[e].x = x, edge[e].y = y, edge[e].v = v;
    edge[e].next = head[x], head[x] = e++;
    edge[e].x = y, edge[e].y = x, edge[e].v = 0;
    edge[e].next = head[y], head[y] = e++;
}
int maxflow(int s, int t) {
    int flow = 0;
    int i, j, x, y;
    while(1) {
        memset(dis, 0, sizeof(dis));
        dis[s] =  0xffff; // oo
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            x = Q.front();
            Q.pop();
            for(i = head[x]; i != -1; i = edge[i].next) {
                y = edge[i].y;
                if(dis[y] == 0 && edge[i].v > 0) {
                    previ[y] = x;
                    record[y] = i;
                    dis[y] = std::min(dis[x], edge[i].v);
                    Q.push(y);
                }
            }
            if(dis[t])  break;
        }
        if(dis[t] == 0) break;
        flow += dis[t];
        for(x = t; x != s; x = previ[x]) {
            int ri = record[x];
            edge[ri].v -= dis[t];
            edge[ri^1].v += dis[t];
        }
    }
    return flow;
}

int main() {
   
    int cases;
    cin >> cases;
    while(cases--) {
        e=0;
        memset(head, -1, sizeof(head));
        int num_t, num_v;
        cin >> num_t >> num_v;
        num_t /= 6;
        int S = 1, T = 8+num_v;
        for(int i=1; i<=6; i++) {
            addEdge(S, i+1, num_t);
        }
        string t1, t2;
        cin.ignore();
        for(int i=0; i<num_v; i++) {
            cin >> t1 >> t2;
            if(t1=="XXL") addEdge(2, 8+i, 1);
            else if(t1=="XL") addEdge(3, 8+i, 1);
            else if(t1=="L") addEdge(4, 8+i, 1);
            else if(t1=="M") addEdge(5, 8+i, 1);
            else if(t1=="S") addEdge(6, 8+i, 1);
            else if(t1=="XS") addEdge(7, 8+i, 1);
            t1=t2;
            if(t1=="XXL") addEdge(2, 8+i, 1);
            else if(t1=="XL") addEdge(3, 8+i, 1);
            else if(t1=="L") addEdge(4, 8+i, 1);
            else if(t1=="M") addEdge(5, 8+i, 1);
            else if(t1=="S") addEdge(6, 8+i, 1);
            else if(t1=="XS") addEdge(7, 8+i, 1);
        }
        
        for(int i=0; i<num_v; i++) {
            addEdge(8+i,T,1);
        }
        int flow = maxflow(S, T);
        if(flow==num_v) cout << "YES\n";
        else cout << "NO\n";     
    }
    
    return 0;
}
