
#include <bits/stdc++.h>
using namespace std;
string line;
bool flag;

pair<int,int> solve(int index, int value){
    if(!flag) return {index,value};
    if(line[index]=='.') return {index,value};
    if(line[index]=='*') return {index,value+1};
    pair<int,int> res;
    res = solve(index+1,value); //left node
    int left = res.second;
    res = solve(res.first+1,value); //right node
    if(abs(left-res.second)>1) flag = false;
    res.second+=left;
    return res;
}
int main(){
    while(getline(cin,line)){
        flag = true;
        solve(0,0);
        if(flag) printf("OK\n");
        else printf("KO\n");
    }
  return 0;
}
