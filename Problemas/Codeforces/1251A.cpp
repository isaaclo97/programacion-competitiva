#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        string line;  cin>>line;
        set<char> S;
        for(unsigned int i=0;i<line.length();i++){
            if(i+1==line.length()) S.insert(line[i]);
            for(unsigned int j=i+1; j<line.length();j++){
                if(line[j]!=line[i] && (j-i)%2!=0)  {
                    S.insert(line[i]); i=j-1; break;
                }
                else if(line[j]!=line[i]) { i=j-1; break; }
                else if(j+1==line.length()) { if((j-i+1)%2!=0) S.insert(line[i]);  i=j+1;}
            }
        }
        for(auto s:S) printf("%c",s);
        printf("\n");
    }
    return 0;
}
