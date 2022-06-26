
#include <bits/stdc++.h>
using namespace std;

int dateToInt(int d, int m, int y) {
    return 1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4+d-32075;
}

int main() {
    int viajes, consultas,d, m, y, d1,m1,y1;

    while (scanf("%d",&viajes)==1 && viajes!=0) {
        vector<int> start, end;
        start.push_back(dateToInt(12, 6, 1968));
        for(int i=0; i<viajes;i++) {
            scanf("%d/%d/%d %d/%d/%d", &d, &m, &y, &d1, &m1, &y1);
            end.push_back(dateToInt(d, m, y));
            start.push_back(dateToInt(d1, m1, y1));
        }
        end.push_back(dateToInt(31, 12, 9999));

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        scanf("%d",&consultas);
        for(int i=0; i<consultas;i++) {
            scanf("%d/%d/%d", &d, &m, &y);
            int date = dateToInt(d, m, y);
            vector<int>::iterator up = upper_bound(start.begin(), start.end(), date);
            vector<int>::iterator low = lower_bound(end.begin(), end.end(), date);
            int res = (up - start.begin()) - (low - end.begin());
            printf("%d\n",res);
        }
        printf("----\n");
    }
    return 0;
}
