
#include <bits/stdc++.h>
using namespace std;
string line;
//abh...ko..nl..a..
//xb..zu..t.u..
int solve(int index){
    if(line[index]=='.') return index;
    if((index+2)<(int)line.length() && line[index+1]==line[index+2] && line[index+2]=='.') printf("%c",line[index]);
    index = solve(index+1); //left node
    index = solve(index+1); //right node
    return index;
}
int main(){
    while(getline(cin,line)){
        solve(0);
        printf("\n");
    }
    return 0;
}
