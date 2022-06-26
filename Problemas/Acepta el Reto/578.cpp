
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0){
        string line;
        set<string> S;
        cin.ignore();
        for(int i=0; i<cases;i++){
            getline(cin,line);
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            S.insert(line);
        }
        printf("%d\n",S.size());
    }
    return 0;
}
