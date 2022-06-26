#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(cin>>n && n!=0) {
        int matrix[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>matrix[i][j];
        int row[n], colum[n];
        memset(row,0,sizeof(row));
        memset(colum,0,sizeof(colum));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                colum[i] += matrix[i][j];
                row[i] += matrix[j][i];
            }
        }
        int r = 0, c = 0, er, ec;
        for(int i = 0; i < n; i++) {
            if(row[i]&1)	r++, er = i;
            if(colum[i]&1)	c++, ec = i;
        }
        if(r == 0 && c == 0)
            cout<<"OK\n";
        else if(r == 1 && c == 1)
            printf("Change bit (%d,%d)\n", ec+1, er+1);
        else
            cout<<"Corrupt\n";
    }
    return 0;
}
