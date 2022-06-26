
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int chessboard[8][8];
int solve(int X,int Y, int remaining, bool board[8][8]){
    if(remaining==0) {
        /*for(int i=0; i<8;i++){
            for(int j=0; j<8;j++) printf("%d",board[i][j]);
            printf("\n");
        }
        printf("-----\n");*/
        return 0;
    }
    if(X==8) {X=0; Y++;}
    if(Y==8) return -INF;
    int flag = 0;
    for(int i=0; i<8 && flag==0;i++) //Row and column check
        if(board[X][i]||board[i][Y]) flag=1;
    for (int i = X, j = Y; i >= 0 && j >= 0 && flag==0; i--, j--)  //Diagonal
           if (board[i][j])  flag=1;
    for (int i = X, j = Y; i < 8 && j < 8 && flag==0; i++, j++)  //Diagonal
           if (board[i][j])  flag=1;
    for (int i = X, j = Y; i >= 0 && j <8 && flag==0; i--, j++)  //Diagonal
           if (board[i][j])  flag=1;
    for (int i = X, j = Y; i <8 && j >= 0 && flag==0; i++, j--)  //Diagonal
           if (board[i][j])  flag=1;
    if(flag==0){
        board[X][Y]=true;
        int val = solve(X+1,Y,remaining-1,board)+chessboard[X][Y];
        board[X][Y]=false;
        return max(val,solve(X+1,Y,remaining,board));
    }
    else {
        return solve(X+1,Y,remaining,board);
    }

}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        for(int i=0; i<8;i++)
            for(int j=0; j<8;j++) scanf("%d",&chessboard[i][j]);
        bool board[8][8]; memset(board,false,sizeof(board));
        printf("%5d\n",solve(0,0,8,board));
    }
    return 0;
}
