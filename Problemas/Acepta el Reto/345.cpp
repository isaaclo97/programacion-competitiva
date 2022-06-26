#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
    int sudoku[9][9];
    bool solve[10];
    bool solv=true;;
    for(int i=0; i<9;i++)
        for(int j=0; j<9;j++)
            cin>>sudoku[i][j];
    //row
    for(int i=0; i<9&&solv;i++)
    {
        memset(solve,false,sizeof(solve));
        for(int j=0; j<9;j++)
        {
            if(solve[sudoku[i][j]])
                solv=false;
            solve[sudoku[i][j]]=true;
        }
    }
    //column
    for(int i=0; i<9&&solv;i++)
    {
        memset(solve,false,sizeof(solve));
        for(int j=0; j<9;j++)
        {
            if(solve[sudoku[j][i]])
                solv=false;
            solve[sudoku[j][i]]=true;
        }
    }
    //3x3
    for(int l=0;l<7;l+=3)
    {
        for(int k=0;k<7;k+=3)
        {
            memset(solve,false,sizeof(solve));
        for(int i=k;i<k+3;i++)
            for(int j=l;j<l+3;j++)
            {
                if(solve[sudoku[i][j]])
                    solv=false;
                solve[sudoku[i][j]]=true;
            }
        }
    }
    if(solv) cout<<"SI\n";
    else cout<<"NO\n";
    }
    return 0;
}
