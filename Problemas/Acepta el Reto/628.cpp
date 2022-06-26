
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int S,G;
    while(scanf("%lld %lld",&S,&G)==2){
        long long int bestS=S,bestG=G;
        bool exist = true;
        while(scanf("%lld %lld",&S,&G)==2 && (S!=0 || G!=0)){
            if(bestS<=S && bestG>=G) {exist = true; bestS = S; bestG=G;}
            else if(bestS<S || bestG>G){ bestS=max(bestS,S); bestG=min(bestG,G); exist = false;}
        }
        if(exist) printf("%lld %lld\n",bestS,bestG);
        else printf("NO HAY MEJOR\n");
    }
    return 0;
}

/*
7 3 8 4 7 2 0 0
7 5 6 2 7 2 0 0
7 2 7 5 6 2 0 0
11 9 12 10 12 8 12 7 11 6 0 0
11 9 12 10 12 8 12 7 11 7 0 0
91 46 83 76 31 20 18 72 61 17 2 49 0 0

NO HAY MEJOR
7 2
7 2
NO HAY MEJOR
12 7
NO HAY MEJOR
*/
