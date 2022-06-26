
#include <bits/stdc++.h>
using namespace std;

//Cuidado con los casos de todo 1s, si no se tiene un caso base bueno dará TLE
// 111111111111111111111111111111111111111111111111111111111111111111111111111
//Caso 1011011 -> 15
//Caso 11 -> 3 | 1111 -> 7 | 111111 -> 11
int acuArray[100002];
int muestras;
long long int solve(int start, int end){
    if((acuArray[end]-acuArray[start-1]) == 0 || start==end) return 0;
    if((acuArray[end]-acuArray[start-1])==(end-start+1)) return 2*(end-start+1)-2;
    int middle = start+(end-start)/2;
    return solve(start,middle) + solve(middle+1,end) + 2;
}
int main(){

    while(scanf("%d",&muestras)==1 && muestras!=0){
        string line; cin.ignore();
        getline(cin,line);
        acuArray[0]=0;
        for(int i=1; i<=line.length();i++){
            acuArray[i]=acuArray[i-1]+(line[i-1]-'0');
        }
        printf("%lld\n",solve(1,line.length())+1);
    }
    return 0;
}
