#include <bits/stdc++.h>
using namespace std;
struct trie {
    trie *next[10];
    bool end;
    trie() {
        for(int i=0; i<10; i++) next[i] = NULL;
        end = false;
    }
};
 
int main() {
    int t, n, i, p;
    char str[15];
    bool flag;
    cin>>t;
    while(t--) {
        cin>>n;
        trie *head, *tail;
        head = new trie;
        flag = true;
        while(n--) {
            cin>>str;
            if(flag) {
                tail = head;
                for(i=0; str[i]; i++) {
                    if(tail->end) {
                        flag = false;
                        break;
                    }
                    p = str[i]-48;
                    if(tail->next[p]==NULL) tail->next[p] = new trie;
                    tail = tail->next[p];
                }
                tail->end = true;
                for(i=0; i<10; i++) {
                    if(tail->next[i]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
} 
