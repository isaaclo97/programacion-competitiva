#include <bits/stdc++.h>
using namespace std;

const char dir[] = "NESW";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    int casos,Q,N,M;
    cin>>casos;
    while (casos--) {
        cin>>N>>M>>Q;
        int G[N][M];
        for(int lm=0;lm<N;lm++)
            for(int pk=0; pk<M;pk++)
                G[lm][pk]=0;
        for (int i = 0; i < Q; i++) {
            char s;
            int x, y, v;
            cin>>x>>y>>s>>v;
            x--; y--;
                    int d = 0;
                    for (int p = 0; p < 4; p++) {
                        if (s == dir[p])
                        {
                            d = p; break;
                        }
                    }
                    if (x >= N || y >= M || x < 0 ||y < 0)
                        break;
                    G[x][y]++;
                    for (int l = 1; l<500; l++) {
                        for (int j = 0; j < 2; j++) {
                            for (int k = 0; k < l; k++) {
                                x += dx[d], y += dy[d];
                                if (x >= N || y >= M || x < 0 ||y < 0)
                                    break;
                                G[x][y]++;
                                v--;
                                if (v == 0)	break;
                            }
                            if (x >= N || y >= M || x < 0 ||y < 0)
                                break;
                             if (v == 0)	break;
                            d = (d + 1)%4;
                        }
                        if (x >= N || y >= M || x < 0 ||y < 0)
                            break;
                         if (v == 0)	break;
                    }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                printf("%d%c", G[i][j], j == M-1 ? '\n' : ' ');
        }
        cout<<"---\n";
    }
    return 0;
}
