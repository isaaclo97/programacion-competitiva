
#include <bits/stdc++.h>
using namespace std;

string line;
int DP[25];

int solve(int idx){
    if(idx==line.length()) return 1;
    int &best = DP[idx];
    if(best!=-1) return best;
    int res = 0;
    if(idx+1<line.length() &&  line[idx]=='I' && line[idx+1]=='I') res+=solve(idx+2); //II
    if(idx+2<line.length() &&  line[idx]=='I' && line[idx+1]=='I' && line[idx+2] == 'I') res+=solve(idx+3); //III
    if(idx+1<line.length() &&  line[idx]=='I' && line[idx+1]=='V') res+=solve(idx+2); //IV
    if(idx+1<line.length() &&  line[idx]=='V' && line[idx+1]=='I') res+=solve(idx+2); //VI
    if(idx+1<line.length() &&  line[idx]=='I' && line[idx+1]=='X') res+=solve(idx+2); //IX
    if(idx+2<line.length() &&  line[idx]=='V' && line[idx+1]=='I' && line[idx+2] == 'I') res+=solve(idx+3); //VII
    if(idx+3<line.length() &&  line[idx]=='V' && line[idx+1]=='I' && line[idx+2] == 'I' && line[idx+3] == 'I') res+=solve(idx+4);//VIII
    res+=solve(idx+1);
    return best = res;
}

int main(){
    while(getline(cin,line)){
        memset(DP,-1,sizeof(DP));
        printf("%d\n",solve(0));
    }
    return 0;
}
