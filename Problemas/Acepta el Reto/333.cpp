
#include <bits/stdc++.h>
using namespace std;

string num;

bool palindrome(int first, int last){
    //cout<<first<<" "<<last<<endl;
    if(num[first]=='0'&&first!=last) return false;
    for(int i=first;i<last && i<(last-i+first);i++)
        if(num[i]!=num[last-i+first]) return false;
    return true;
}

int main(){
    cin>>num;
    while(num!="0"){
        if(num.length()==2) printf("SI\n");
        else if(num.length()==1) printf("NO\n");
        else{
            bool cap = false;
            for(unsigned int i=0; i<num.length() && !cap && (i+1)<=(num.length()-1);i++){
                if(palindrome(0,i) && palindrome(i+1,num.length()-1)) cap=true;
            }
            if(cap) printf("SI\n");
            else printf("NO\n");
        }
        cin>>num;
    }
    return 0;
}
