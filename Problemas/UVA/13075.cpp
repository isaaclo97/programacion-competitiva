#include <bits/stdc++.h>
using namespace std;

int main() {
    int casos;
    scanf("%d", &casos);
    while (casos--) {
        int C, V, A[17] = {};
        char s[17], mm[3] = "CV";
        scanf("%d %d", &C, &V);
        for (int i = C; i < C+V; i++)
            A[i] = 1;

        int f = 0;
        do {
            for (int i = 0; i < C+V; i++)
                s[i] = mm[A[i]];
            s[C+V] = '\0';
            if (f)	putchar(' ');
            printf("%s", s), f = 1;
        } while (next_permutation(A, A+C+V));
        puts("");
    }
    return 0;
}
