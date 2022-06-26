
#include <bits/stdc++.h>
using namespace std;
string arr[]={"h", "li", "na", "k", "rb", "cs", "fr",
              "be", "mg", "ca", "sr", "ba", "ra",
              "sc", "y",
              "ti", "zr", "hf", "rf",
              "v", "nb", "ta", "db",
              "cr", "mo", "w", "sg",
              "mn", "tc", "re", "bh",
              "fe", "ru", "os", "hs",
              "co", "rh", "ir", "mt",
              "ni", "pd", "pt", "ds",
              "cu", "ag", "au", "rg",
              "zn", "cd", "hg", "cn",
              "b", "al", "ga", "in", "tl", "nh",
              "c", "si", "ge", "sn", "pb", "fl",
              "n", "p", "as", "sb", "bi", "mc",
              "o", "s", "se", "te", "po", "lv",
              "f", "cl", "br", "i", "at", "ts",
              "he", "ne", "ar", "kr", "xe", "rn", "og",
              "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
              "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
map<string,bool> table;
string res;
map<int,bool> memo;

bool solve(int current){
    if(current==(int)(res.size())) return true;
    if(memo.count(current)) return memo[current];
    string check = "";
    for (int i = current; i < current + 2 && i < res.length(); i++) {
        check+=res[i];
        if (!table[check]) continue;
        if (solve(i + 1)) {
            memo[current]=true;
            return true;
        }
    }
    memo[current]=false;
    return false;
}

int main(){
    string line;
    for(int i=0; i<118;i++) table[arr[i]]=true;
    while(getline(cin,line)){
        res = "";
        for(unsigned int i=0; i<line.length();i++){
            if(line[i]==' ') continue;
            res+=tolower(line[i]);
        }
        memo.clear();
        if(solve(0)) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
