#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main() {
    int cases,n;
    cin>>cases;
    while(cases--) {
        cin>>n;
        queue <int> deck;
        vector <int> B;
        int C[20001];
        for(int i=1; i<=n; i++) deck.push(i);
        for(int i=1; i<=n; i++)	{
            int j=i;
            while(j--) {
                int card=deck.front();
                deck.pop();
                deck.push(card);
            }
            int card=deck.front();
            deck.pop();
            B.push_back(card);
        }
        for(int i=1; i<=n; i++) C[B[i-1]]=i;
        for(int i=1;i<=n; i++)  printf("%d ",C[i]);
        printf("\n");
    }
    return 0;
}
