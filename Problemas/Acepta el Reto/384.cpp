#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    while (scanf("%d", &n) == 1) {
        int arr[n],temp,flag=0,inter=1;
        scanf("%d", &temp);
        arr[0] = arr[1] = temp;
        n--;
        while(n!=0) {
            n--;
            scanf("%d", &temp);
            for (int i = inter; i > 0 && arr[i - 1] < temp && flag==0; i -= 2)
                if (arr[i - 1] < temp && arr[i] > temp) flag = 1;
            if (flag) break;
            if (arr[inter - 1] < temp)  arr[inter] = temp;
            else if (arr[inter - 1] == arr[inter]) arr[inter - 1] = arr[inter] = temp;
            else {
                inter += 2;
                arr[inter - 1] = arr[inter] = temp;
            }
        }
        while(n!=0) { n--; scanf("%d", &temp); }
        if (flag) printf("ELEGIR OTRA\n");
        else printf("SIEMPRE PREMIO\n");
    }
    return 0;
}
