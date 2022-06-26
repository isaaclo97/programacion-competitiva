
#include <bits/stdc++.h>
using namespace std;

int par[1000005];
int size[1000005]; //cuidado unsigned

char matrix[1005][1005];

int dx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int dy[]={0,0,1,-1,1,-1,1,-1};
int F,C;

int root(int i){
    if (par[i] == i)
        return i;
    else
        return par[i] = root(par[i]);
}

void merge(int a, int b){
    int p = root(a);
    int q = root(b);
    if (p == q)
        return;
    if (size[p] > size[q])
        swap(p, q);

    par[p] = q;
    size[q] += size[p];
}

int main(){
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\tricky.in","r",stdin);
    while(scanf("%d %d",&F,&C)==2){
        cin.ignore();
        for(int i=0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%c",&matrix[i][j]);
            }
            cin.ignore();
        }

        int res = 0;
        for (int i = 0; i < F*C + 1; i++) {
            par[i] = i;
            size[i] = 1;
        }

        for(int i=0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if(matrix[i][j] == '#'){
                    for (int n = 0; n < 8; n++) {
                        int I = i + dx[n];
                        int J = j + dy[n];
                        if (I >= 0 && I < F && J >= 0 && J < C && matrix[I][J] == '#') {
                            int node1 = I*C+J;
                            int node2 = i*C+j;
                            //if(node1>F*C ||node2>F*C) cout<<"BUG\n";
                            if (root(node1) != root(node2)) {
                                int size1 = size[root(node1)];
                                int size2 = size[root(node2)];
                                merge(node1, node2);
                                res = max(size1+size2,res);
                            }
                        }
                    }
                    res=max(res,1); //caso especial
                }
            }
        }
        printf("%d",res); //Cuidado caso vacío
        int cases,a,b;
        scanf("%d",&cases);
        while(cases--){
            scanf("%d %d",&a,&b);
            a--; b--;
            matrix[a][b] = '#';
            res=max(res,1); //caso especial
            for (int i = 0; i < 8; i++) {
                int I = a + dx[i];
                int J = b + dy[i];
                if (I >= 0 && I < F && J >= 0 && J < C && matrix[I][J] == '#') {
                    int node1 = I*C+J;
                    int node2 = a*C+b;
                    //if(node1>F*C ||node2>F*C) cout<<"BUG\n";
                    if (root(node1) != root(node2)) {
                        int size1 = size[root(node1)];
                        int size2 = size[root(node2)];
                        merge(node1, node2);
                        res = max(size1+size2,res);
                    }
                }
            }
            printf(" %d",res);
        }
        printf("\n");
    }
    return 0;
}
