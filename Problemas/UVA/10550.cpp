#include <bits/stdc++.h>
using namespace std;
int main()
{
    int start, first, second, third;
    while (scanf("%d %d %d %d", &start, &first, &second, &third), (start || first || second || third))
    {
        printf("%d\n", 1080 + ((start - first + 40) % 40 + (second - first + 40) % 40 + (second - third + 40) % 40) * 9);
    }
}
