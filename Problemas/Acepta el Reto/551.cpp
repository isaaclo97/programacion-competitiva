
#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        for(unsigned int i=0; i<line.length();i+=2){
            string s;
            if(line[i]=='1') { s=line.substr(i,3); i++; }
            else s=line.substr(i,2);
            int ascii=stoi(s);
            cout<<(char)ascii;
        }
        printf("\n");
    }
    return 0;
}
