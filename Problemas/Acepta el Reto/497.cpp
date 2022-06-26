#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 10005
using namespace std;

int costs [N];
int freq [N];
vector <int> edges [N];
int n;

int bfs (int at)
{
    for ( int i = 0; i < N; i++ ) costs [i] = INF;
    costs [at] = 0;
    queue <int> q;
    q.push (at);
    while ( !q.empty () ) {
        int p = q.front ();
        q.pop ();
        for (unsigned int i = 0; i < edges [p].size (); i++ )
            if ( costs [edges [p].at (i)] == INF ) {
                costs [edges [p].at (i)] = costs [p] + 1;
                q.push (edges [p].at (i));
            }
    }
    int ret = 0;
    for ( int i = 1; i <= n; i++ )
        if ( freq [i] >= 2 ) ret += costs [i];
    return ret;
}

int main ()
{
    int s;
    while (scanf ("%d %d", &n, &s)==2 && (n!=0 || s!=0)) {
        for ( int i = 0; i <= n; i++ ) freq[i]=0;
        int min_cost = INF,output;;
        for ( int i = 0; i < s; i++ ) {
            int curr;
            int prev;
            scanf ("%d", &curr);
            freq [curr]++;
            prev = curr;
            while ( scanf ("%d", &curr) && curr ) {
                freq [curr]++;
                edges [curr].push_back (prev);
                edges [prev].push_back (curr);
                prev = curr;
            }
        }
        for ( int i = 1; i <= n; i++ )
            if ( freq [i] >= 2 ) {
                int c = bfs (i);
                if ( c < min_cost ) {
                    min_cost = c;
                    output = i;
                }
            }
        printf ("%d\n", output);
        for ( int i = 0; i <= n; i++ ) edges [i].clear ();
    }
    return 0;
}
