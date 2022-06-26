
#include <bits/stdc++.h>
using namespace std;

int matrix[305][305];
int maxX[305];
int maxY[305];
int minX[305];
int minY[305];

int main(){
    int F,C;
    while(scanf("%d %d",&F,&C)==2 && (F!=0 || C!=0)){
        for(int i=0; i<F;i++) {
            int maxI = -0x3f3f3f;
            int minI = 0x3f3f3f;
            for (int j = 0; j < C; j++) {
                scanf("%d", &matrix[i][j]);
                maxI = max(maxI,matrix[i][j]);
                minI = min(minI,matrix[i][j]);
            }
            maxX[i]=maxI;
            minX[i]=minI;
        }

        for(int i=0; i<C;i++) {
            int maxI = -0x3f3f3f;
            int minI = 0x3f3f3f;
            for (int j = 0; j < F; j++) {
                maxI = max(maxI,matrix[j][i]);
                minI = min(minI,matrix[j][i]);
            }
            maxY[i]=maxI;
            minY[i]=minI;
        }
        bool exist = false;
        for(int i=0; i<F && !exist;i++)
            for(int j=0; j<C && !exist;j++) {
                //<= de su fila y >= de su columna
                if(matrix[i][j]<=minX[i] && matrix[i][j]>=maxY[j]) exist = true;
                //>= de su fila y <= de su columna
                if(matrix[i][j]>=maxX[i] && matrix[i][j]<=minY[j]) exist = true;
            }
        if(exist) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
