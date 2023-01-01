#include <bits/stdc++.h>
using namespace std;

string filterLine(string line){
    string res = "";
    for(int i=0; i<line.length();i++){
        if(tolower(line[i])>='a' && tolower(line[i])<='z')
            res+=tolower(line[i]);
    }
    return res;
}
int main() {
    int cases; scanf("%d",&cases); cin.ignore();
    while(cases--){
        string line,line2;
        getline(cin,line);
        getline(cin,line2);
        line = filterLine(line);
        line2 = filterLine(line2);
        if(line==line2) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}