
#include <bits/stdc++.h>
using namespace std;

int pruebaBaseB(string s, int B){
    long long int res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A')  res+=(10+s[i]-'A');
        else res+=(s[i]-'0');
    }
    return res%(B-1);
}
int main() {
    int cases,B; scanf("%d",&cases);
    string D, d, c, r;
    while(cases--){
        cin>>B>>D>>d>>c>>r;
        //(D = d · c + r).
        int value = ((pruebaBaseB(d,B)*pruebaBaseB(c,B))+pruebaBaseB(r,B))%(B-1);
        if(pruebaBaseB(D,B)==value) printf("POSIBLEMENTE CORRECTO\n");
        else  printf("INCORRECTO\n");
    }
    return 0;
}
