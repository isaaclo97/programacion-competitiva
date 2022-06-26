
#include <bits/stdc++.h>
using namespace std;

int acum[1005][1005];
int matrix[1005][1005];
int tx,ty,mx,my;

int preProcess(){
    for (int i=0; i<ty; i++)
        acum[0][i] = matrix[0][i];
    for (int i=1; i<tx; i++)
        for (int j=0; j<ty; j++)
            acum[i][j] = matrix[i][j] + acum[i-1][j];
    for (int i=0; i<tx; i++)
        for (int j=1; j<ty; j++)
            acum[i][j] += acum[i][j-1];
}

int sumQuery(int tli, int tlj, int rbi,int rbj){
    int res = acum[rbi][rbj];
    if (tli > 0) res = res - acum[tli-1][rbj];
    if (tlj > 0) res = res - acum[rbi][tlj-1];
    if (tli > 0 && tlj > 0) res = res + acum[tli-1][tlj-1];
    //cout<<res<<" "<<tli<<" "<<tlj<<" "<<rbi<<" "<<rbj<<endl;
    return res;
}

int main(){
    while(scanf("%d %d %d %d",&ty,&tx,&my,&mx) == 4 && (tx!=0 || ty!=0 || mx!=0 || my!=0)){
        map<int,int> res;
        string line;
        for(int i=0; i<tx;i++){
            cin>>line;
            for(int j=0; j<ty;j++){
                if(line[j]=='X') matrix[i][j]=1;
                else matrix[i][j]=0;
            }
        }
        /*for(int i=0; i<tx;i++){
            for(int j=0; j<ty;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }*/
        preProcess();
        /*cout<<"---\n";
        for(int i=0; i<tx;i++){
            for(int j=0; j<ty;j++){
                printf("%d ",acum[i][j]);
            }
            printf("\n");
        }*/
        for(int i=0; (i+mx-1)<tx;i++){
            for(int j=0; (j+my-1)<ty;j++){
                int ex = i+mx-1;
                int ey = j+my-1;
                res[sumQuery(i,j,ex,ey)]++;
            }
        }
        for(int i=0; i<=7; i++){
            if(i==0) printf("%d",res[i]);
            else printf(" %d",res[i]);
        }
        printf("\n");
    }
    return 0;
}
