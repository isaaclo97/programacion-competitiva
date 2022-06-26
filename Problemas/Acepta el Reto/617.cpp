
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int words; scanf("%d",&words); cin.ignore();
        vector<string> V; string name;
        for(int i=0; i<words;i++){
            getline(cin,name);
            V.push_back(name);
        }
        for(int j=0; j<3;j++){
            for(int i=0; i<words;i++){
                printf("%c",V[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
