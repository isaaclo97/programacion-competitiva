#include <bits/stdc++.h>
#define oo 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const int MAXV = 2005;

struct KM {
    int _mem[MAXV*MAXV];
    int *w[MAXV];
    int lx[MAXV], ly[MAXV];
    int16_t mx[MAXV], my[MAXV];
    int16_t aug[MAXV], vis[MAXV];
    pair<int, int> slack[MAXV];
    int nx, ny;


    int match() {
        for (int i = 0; i < nx; i++)
            lx[i] = *max_element(w[i], w[i]+ny); fill(ly, ly+ny, 0);
        fill(mx, mx+nx, -1);
        fill(my, my+ny, -1);
        fill(slack, slack+ny, make_pair(0, 0));
        for (int root = 0; root < nx; root++){
            fill(aug, aug+ny, -1);
            fill(vis, vis+nx, 0);
            vis[root] = 1;
            for (int y = 0; y < ny; y++)
                slack[y] = make_pair(lx[root]+ly[y]-w[root][y], root);
            int sy = -1;
            for (;;) {
                int delta = INT_MAX, sx = -1;
                for (int y = 0; y < ny; y++) {
                    if (aug[y] == -1 && slack[y].first < delta) {
                        delta = slack[y].first; sx = slack[y].second, sy = y;
                    }
                }
                // assert(vis[sx]);
                if (delta > 0) {
                    for (int x = 0; x < nx; x++) {
                        if (vis[x]) lx[x] -= delta;
                    }
                    for (int y = 0; y < ny; y++) {
                        if (aug[y] > -1) ly[y] += delta;
                        else slack[y].first -= delta;
                    }
                }
                // assert(lx[sx] + ly[sy] == w[sx][sy]);
                aug[sy] = sx; sx = my[sy];
                if (sx == -1) break;
                vis[sx] = 1;
                for (int y = 0; y < ny; y++) {
                    if (aug[y] == -1) {
                        if (lx[sx]+ly[y]-w[sx][y] < slack[y].first)
                            slack[y] = make_pair(lx[sx]+ly[y]-w[sx][y], sx);
                    }
                }
            }
            while (sy != -1) {
                int sx = aug[sy];
                int ty = mx[sx];
                my[sy] = sx;
                mx[sx] = sy;
                sy = ty;
            }
        }
        int ret = 0;
        for (int i = 0; i < nx; i++)
            ret += lx[i];
        for (int i = 0; i < ny; i++)
            ret += ly[i];
        return ret;
    }

    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        for (int i = 0; i < nx; i++)
            w[i] = _mem + i*ny;
    }
} km;

int main() {
    int numVine, numCouriers;
    const int MAXN = 2005;
    int bottlex[MAXN], bottley[MAXN];
    int courierx[MAXN], couriery[MAXN];
    int retuaurantx, restauranty;
    while (scanf("%d %d", &numVine, &numCouriers) == 2) {
        for (int i = 0; i < numVine; i++)
            scanf("%d %d", &bottlex[i], &bottley[i]);
        for (int i = 0; i < numCouriers; i++)
            scanf("%d %d", &courierx[i], &couriery[i]);
        scanf("%d %d", &retuaurantx, &restauranty);
        km.init(numVine, numCouriers+(numVine-1));

        //suma acumulada de distnacias de restaurante a vino.
        int ret = 0;

        for (int i = 0; i < numVine; i++) {

            int b = abs(bottlex[i]-retuaurantx)+abs(bottley[i]-restauranty);
            ret += b; //incremento
            //Presupones que tendrás que hacer el trayecto botella->restaurante
            //al menos una vez por cada botella.
            //asi que solo apuntas las distnacias casa->botella y rest->botella

            for (int j = 0; j < numCouriers; j++) {
                //distancia entre cada botella y cada repartidor
                int d = abs(bottlex[i]-courierx[j])+abs(bottley[i]-couriery[j]);
                km.w[i][j] = -d;
            }
            for (int j = 0; j < numVine-1; j++)
                //distancia entre cada botella y el restaurante
                //Añades esto numVinos-1 veces para asegurar que al menos un camino es
                //desde la casa de uno de los repartidores
                km.w[i][j+numCouriers] = -b;
        }
        //Según este planteamiento una botella tiene que ser asignada o al restaurante(repartidor virtual) o a un repartidor.
        //Y al menos una botella será repartida por un repartidor normal, ya que solo hay numBotellas-1 de los virtuales.
        ret += -km.match();
        printf("%d\n", ret);
    }
    return 0;
}
