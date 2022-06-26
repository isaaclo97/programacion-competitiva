
#include <bits/stdc++.h>
using namespace std;

int same_digits(int n){
    string num = to_string(n);
    for(unsigned int i=1;i<num.length();i++)
        for(unsigned int j=0;j<i;j++)
            if(num[i]==num[j]) return 1;
    return 0;
}

int main(){
    int cases,number; scanf("%d",&cases);
    while(cases--){
        scanf("%d",&number);
        int rep = same_digits(number);
        int aux_rep = rep;
        int aux_number = number;
        while(rep==aux_rep){
            aux_number--;
            rep = same_digits(aux_number);
        }
        aux_number++;
        int serie = aux_number;
        aux_number = number;
        rep = aux_rep;
        while(rep==aux_rep){
            aux_number++;
            rep = same_digits(aux_number);
        }
        aux_number--;
        int resultado = aux_number - serie + 1;
        printf("%d %d\n",serie,resultado);
    }
    return 0;
}
