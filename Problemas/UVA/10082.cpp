#include <bits/stdc++.h>
using namespace std;
#define Key "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"

int main() {
    int m = strlen(Key);
    string s;
    while (getline(cin,s)) {
        int n = s.length();
        for (int i=0; i<n; i++)
            if (s[i]==' ') printf(" ");
            else {
                for (int j=0; j<m; j++)
                    if (s[i]==Key[j]) {
                        printf("%c", Key[j-1]);
                        break;
                    }
            }
        cout << endl;
    }
}
