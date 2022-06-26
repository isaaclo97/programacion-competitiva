#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, m;
    while (scanf("%d%d", &k, &m) == 2)
    {
        unsigned int diff = abs(k-m);
        unsigned int numSeconds = (43200 * (86400 - k) / diff) % 43200 + 30;
        unsigned int hour = numSeconds / 3600 % 12;
        unsigned int min = numSeconds / 60 % 60;
        printf("%d %d %02d:%02d\n", k, m, hour == 0 ? 12 : hour, min);
    }
    return 0;
}
