#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Desktop/out.txt","w",stdout);
    int n, op, x;
        while (scanf("%d", &n) ==1) {
            queue<int> q;
            stack<int> s;
            priority_queue<int> pq;
            bool isS = true, isQ = true, isPQ = true;

            for (int i = 0; i < n; i++) {
                scanf("%d %d", &op, &x);
            if(op==1){
                    if (isS)  s.push(x);
                    if (isQ)  q.push(x);
                    if (isPQ) pq.push(x);
            }
            else{
                    if (isS)   if (s.empty() || s.top() != x)  isS = false;
                               else s.pop();
                    if (isQ)   if (q.empty() || q.front() != x) isQ = false;
                               else q.pop();

                    if (isPQ)  if (pq.empty() || pq.top() != x) isPQ = false;
                               else pq.pop();
                }
            }
            if (isS == true && isQ == false && isPQ == false)      cout << "stack" << endl;
            else if (isS == false && isQ == true && isPQ == false) cout << "queue" << endl;
            else if (isS == false && isQ == false && isPQ == true) cout << "priority queue" << endl;
            else if (isS == false && isQ == false && isPQ == false)cout << "impossible" << endl;
            else cout << "not sure" << endl;
        }
    return 0;
}
