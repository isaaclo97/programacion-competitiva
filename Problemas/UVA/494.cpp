#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(getline (cin,str)) {
        int i, flag = 0, count = 0;
                for(i = 0; str[i]; i++) {
                    if((str[i] >= 'A' && str[i] <= 'Z') ||
                        (str[i] >= 'a' && str[i] <= 'z'))
                            flag = 1;
                    else {
                        count += flag;
                        flag = 0;
                    }
                }
                count += flag;
                cout<<count<<endl;
    }
 return 0;
}
