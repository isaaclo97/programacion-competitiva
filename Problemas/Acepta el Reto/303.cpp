#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

bool esArbolAVL(int &altura, int &mini, int &maxi) {
    int alturaIz, alturaDr, minIz, minDr, maxIz, maxDr;
    bool esAVLIz, esAVLDr, esBusqueda;

    int raiz; scanf("%d",&raiz);

    if (raiz == -1) {
        altura = 0;
        mini = INF;
        maxi = -INF;
        return true;
    }
    esAVLIz = esArbolAVL(alturaIz, minIz, maxIz);
    esAVLDr = esArbolAVL(alturaDr, minDr, maxDr);
    altura = max(alturaDr, alturaIz) + 1;
    mini = min(min(minDr, minIz), raiz);
    maxi = max(max(maxDr, maxIz), raiz);
    esBusqueda = maxIz < raiz && raiz < minDr;
    return esAVLDr && esAVLIz && esBusqueda && abs(alturaDr - alturaIz) <= 1;
}

int main() {
    int ca; scanf("%d",&ca);
    while(ca--) {
        int altura, min, max;
        if (esArbolAVL(altura, min, max))  printf("SI\n");
        else  printf("NO\n");
    }
    return 0;
}
