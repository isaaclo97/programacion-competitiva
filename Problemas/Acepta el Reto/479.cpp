#include <bits/stdc++.h>
using namespace std;

int main()
{
    int filas,columnas;
    while(scanf("%d%d",&filas,&columnas)==2 && (filas!=0 || columnas!=0))
    {
        bool matrix[filas][columnas]; memset(matrix,false,sizeof(matrix));
        cin.ignore();
        string line;
        for(int i=0; i<filas;i++)
        {
            getline(cin,line);
            for(int j=0; j<columnas;j++)
            {
                matrix[i][j] = line[j] == 'X';
            }
        }
        int cases; scanf("%d",&cases);
        for (int i = 0; i < cases; i++) {
                int y, x; scanf("%d%d",&y,&x); x--; y--;
                string direction; cin>>direction;
                int desplazamiento = 0;
                if(direction == "ARRIBA"){
                    while(y - desplazamiento >= 0 && !matrix[y - desplazamiento][x]){
                        desplazamiento++;
                    }
                    if(y - desplazamiento < 0) printf("NINGUNO\n");
                    else printf("%d\n",desplazamiento);

                } else if (direction == "ABAJO"){
                    while(y + desplazamiento < filas && !matrix[y + desplazamiento][x]){
                        desplazamiento++;
                    }
                    if(y + desplazamiento >= filas)  printf("NINGUNO\n");
                    else printf("%d\n",desplazamiento);

                } else if(direction == "IZQUIERDA"){
                    while(x - desplazamiento >= 0 && !matrix[y][x - desplazamiento]){
                        desplazamiento++;
                    }
                    if(x - desplazamiento < 0) printf("NINGUNO\n");
                    else printf("%d\n",desplazamiento);

                } else if(direction == "DERECHA"){
                    while(x + desplazamiento < columnas && !matrix[y][x + desplazamiento]){
                        desplazamiento++;
                    }
                    if(x + desplazamiento >= columnas) printf("NINGUNO\n");
                    else printf("%d\n",desplazamiento);
                }
            }
            printf("---\n");
    }
    return 0;
}
