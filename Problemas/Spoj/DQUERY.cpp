#include <bits/stdc++.h>
using namespace std;
const int MAX = 300005;
const int MAX1 = 1e6+5;
int BIT[MAX], p[MAX1], ans[MAX], a[MAX];
pair <int, pair<int, int> > pr[MAX];

void update(int idx, int val)
{
    while(idx < MAX)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    int n, q, x;
    while(scanf("%d", &n)==1)
    {
        for(int i = 1;i <= n;++i) scanf("%d", &a[i]);
        scanf("%d", &q);
        for(int i = 0;i < q;i++)
        {
            scanf("%d %d", &pr[i].second.first, &pr[i].first);
            pr[i].second.second = i;
        }
        sort(pr, pr + q);
        memset(p, -1, sizeof(p));
        memset(BIT, 0, sizeof(BIT));
        x = 0;
        for(int i = 1;i <= n;i++)
        {
            if(p[a[i]] != -1) update(p[a[i]], -1);
            p[a[i]] = i;
            update(i, 1);
            while(x < q and pr[x].first == i)
            {
                ans[pr[x].second.second] = read(pr[x].first) - read(pr[x].second.first-1);
                x++;
            }
        }
        for(int i = 0;i < q; i++)  printf("%d\n", ans[i]);
    }
    return 0;
}
