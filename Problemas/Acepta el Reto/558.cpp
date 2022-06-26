
#include <bits/stdc++.h>
using namespace std;

string tolowerWord(string w){
    string res;
    for(unsigned int i=0; i<w.length();i++)
        res+=tolower(w[i]);
    return res;
}
int main(){
    int cases;
    while(scanf("%d",&cases)==1){
        map<string,int> M;
        map<string,string> M2;
        vector<string> V;
        for(int i=0; i<cases;i++){
            string line; cin>>line;
            int cnt=0;
            for(unsigned int i=0; i<line.length();i++){
                if(line[i]>='A' && line[i]<='Z') cnt++;
            }
            string word = tolowerWord(line);
            //Simplemente es devolver las palabras que contengan mas mayusculas aunque no empiece por mayuscula
            if(M[word]<cnt || M[word]==0) { M2[word]=line; M[word]=cnt;}
            V.push_back(word);
        }
        for(int i=0; i<cases;i++) cout<<M2[V[i]]<<'\n';
        cout<<"---\n";
    }
    return 0;
}
/*
2
cDA
cDa

cDA
cDA

2
Cda
cDA

cDA
cDA
*/
