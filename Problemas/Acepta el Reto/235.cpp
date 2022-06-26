
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    char matrix[2755][4][4];
    char check[4][4];
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0)){
        cin.ignore();
        int index = -1,i_index=0,j_index=0,last=-1;
        for(int i=0; i<n*3;i++,i_index++){
            if(i%3==0 && i!=0)  { i_index=0; last=index;}
            else index=last;
            for(int j=0; j<m*3;j++,j_index++)
            {
                if(j%3==0) { index++; j_index=0; }
                scanf("%c",&matrix[index][i_index][j_index]);
            }
            j_index=0;
            cin.ignore();
        }
        int cases; scanf("%d",&cases); cin.ignore();
        bool flag=false,next=false;
        int sol;
        while(cases--){
            for(int k=0; k<3;k++) {
                for(int l=0; l<3;l++) scanf("%c",&check[k][l]);
                cin.ignore();
            }
            for(int i=0; i<n*m && !flag;i++){
                for(int k=0; k<3 && !next;k++)
                    for(int l=0; l<3 && !next;l++)
                        if(check[k][l]!=matrix[i][k][l]) next=true;
                if(!next) { flag=true; sol=i;}
                next=false;
            }
            if(flag) printf("%d %d\n",sol/m+1,sol%m+1);
            else printf("NO SE USA\n");
            flag=false;
        }
    }
    return 0;
}
