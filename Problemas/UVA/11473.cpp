#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-15
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};

double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

int main()
{
    int cases,n,m,ca=1;
    while(scanf("%d",&cases)==1)
    {
        while(cases--)
        {
            scanf("%d%d",&n,&m);
            vector<point> V;
            double x,y;
            for(int i=0; i<n;i++)
            {
                scanf("%lf %lf",&x,&y);
                V.push_back(point(x,y));
            }
            double dista = 0;
            printf("Road #%d:\n",ca++);
            printf("%.2lf %.2lf\n",V[0].x,V[0].y);
            for(unsigned int i=0; i<V.size()-1;i++)
                dista+=dist(V[i],V[i+1]);
            dista/=((double) m-1);
            double distacu = 0;
            int cont = 1;
            for(unsigned int i=0; i<V.size()-1;i++)
            {
                double distactual = dist(V[i],V[i+1]);
                double xuni = (V[i+1].x-V[i].x)/distactual;
                double yuni = (V[i+1].y-V[i].y)/distactual;
                if(distactual+distacu>=dista)
                {
                    double recorrido=dista-distacu;
                    while(recorrido<=distactual)
                    {
                    cont++;
                    //sacar punto
                    printf("%.2lf %.2lf\n",V[i].x+recorrido*xuni,V[i].y+recorrido*yuni);
                    recorrido+=dista;
                    //dista = longitud donde plantar arbol
                    //distactual = distancia segmento actual
                    //distacu = distancia acumulada anterior
                    //recorrido parte distancia actual usada
                    }
                    distacu = distactual-(recorrido-dista);
                }
                else distacu +=distactual;
            }
            if(cont!=m) printf("%.2lf %.2lf\n",V[V.size()-1].x,V[V.size()-1].y);
            printf("\n");
        }
    }
    return 0;
}
