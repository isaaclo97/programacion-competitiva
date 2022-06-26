#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
   
    int B[3], G[3], C[3];

    while (scanf("%d %d %d %d %d %d %d %d %d", &B[0], &G[0], &C[0], &B[1],&G[1], &C[1], &B[2], &G[2], &C[2])==9) {
        int min = INF, temp;
        string ans;
        //BCG
        temp = C[0] + G[0] + B[1] + G[1] + B[2] + C[2];
        if (temp < min) {
            min = temp;
            ans="BCG";
        }
        //BGC
        temp = C[0] + G[0] + B[1] + C[1] + B[2] + G[2];
        if (temp < min) {
            min = temp;
            ans="BGC";
        }
        //CBG
        temp = B[0] + G[0] + C[1] + G[1] + B[2] + C[2];
        if (temp < min) {
            min = temp;
            ans="CBG";
        }
        //CGB
        temp = B[0] + G[0] + B[1] + C[1] + G[2] + C[2];
        if (temp < min) {
            min = temp;
            ans="CGB";
        }
        //GBC
        temp = C[0] + B[0] + C[1] + G[1] + B[2] + G[2];
        if (temp < min) {
            min = temp;
            ans="GBC";
        }
        //GCB
        temp = C[0] + B[0] + B[1] + G[1] + G[2] + C[2];
        if (temp < min) {
            min = temp;
            ans="GCB";
        }
        cout<<ans<<" "<<min<<'\n';
    }
    return 0;
}
