
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    string n1,n2;
    scanf("%d",&cases); cin.ignore();
    while(cases--){
        cin>>n1>>n2;
        map<char,int> m1,m2;
        for(int i=0; i<n1.length();i++){
            m1[n1[i]]++;
            m2[n2[i]]++;
        }
        bool flag = true;
        for(auto n:m1){
            if(m2[n.first]!=m1[n.first]) {
                flag = false;
                break;
            }
        }
        if(flag) printf("GANA\n");
        else printf("PIERDE\n");
    }
    return 0;
}
