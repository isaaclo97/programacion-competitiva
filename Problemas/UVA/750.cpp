#include <bits/stdc++.h>
using namespace std;

int col[9], cases, a, b, cnt;

bool place(int Q, int row){
    for(int ant = 1; ant < Q ; ant++)
        if(col[ant] == row || (abs(col[ant] - row) == abs(ant - Q)))
            return false;
    return true;
}

void solve(int Q)
{
    for(int row = 1; row <= 8; row++)
        if(place(Q, row)){
            col[Q] = row;
            if(Q == 8 && col[b] == a){
                printf("%2d      %d", ++cnt, col[1]);
                for(int j = 2; j <= 8; j++)
                    printf(" %d", col[j]);
                printf("\n");
            }
            else solve(Q+1);
        }
}
int main()
{
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &a, &b);
        memset(col, 0, sizeof(col));
        cnt = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(1);
        if(cases) printf("\n");
    }
    return 0;
}
