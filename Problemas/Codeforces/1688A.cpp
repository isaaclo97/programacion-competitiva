
#include <bits/stdc++.h>
using namespace std;
 
string bin(long long int n){
    long long int  i;
    string res = "0";
    for (i = 1 << 30; i > 0; i = i / 2){
        if((n & i) != 0) res+="1";
        else res+="0";
    }
    return res;
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        long long int number; scanf("%lld",&number);
        string num = bin(number);
        //cout<<num<<endl;
        string res = "";
        int unos=0;
        for(int i=0; i<num.length();i++){
            if(num[i]=='1') unos++;
        }
        if(unos==1){
            for(int i=num.length()-1; i>=0;i--){
                if(num[i]=='0') {
                    num[i] = '1';
                    break;
                }
            }
        }
        else{
            bool flag = false;
            for(int i=num.length()-1; i>=0;i--){
                if(flag) num[i]='0';
                if(num[i]=='1') {
                    flag=true;
                }
            }
        }
        cout<<stoi(num, 0, 2)<<endl;
    }
    return 0;
}
