#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int ca = 1, aux;
    cin >> aux;
    while(aux--)
    {
        int N,R;
        cin>>N>>R;

        vector<vector<int>> buildings(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++)  buildings[i][i] = 0;
        for (int i = 0; i < R; i++)
        {
            int u, v;
            cin>>u>>v;
            buildings[u][v] = 1;
            buildings[v][u] = 1;
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                   buildings[i][j] = min(buildings[i][j], buildings[i][k] + buildings[k][j]);

        int s, d;
        cin>>s>>d;
        int res = 0;
        for (int i = 0; i < N; ++i)
            if (buildings[s][i] != INF && buildings[i][d] != INF)
                res = max(res, buildings[s][i] + buildings[i][d]);
        printf("Case %d: %d\n",ca++,res);
    }
    return 0;
}

