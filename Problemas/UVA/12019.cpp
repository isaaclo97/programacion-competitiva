#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int Month[13][32], i, j;
        int day = 6, Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //last day is 6 (Saturday)
        for(i = 12; i >= 1; i--) {
            for(j = Day[i]; j >= 1; j--) {
                Month[i][j] = day;
                day--;
                if(day < 1)	day = 7;
            }
        }
        char s[8][10] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int T;
        cin>>T;
        while(T--) {
            scanf("%d %d", &i, &j);
            printf("%s\n", s[Month[i][j]]);
        }
    return 0;
}
