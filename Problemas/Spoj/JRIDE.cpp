
#include <bits/stdc++.h>
using namespace std;

int main(){
    int roads,cases=1; scanf("%d",&roads);
    while(roads--){
        int stops,first=0,last=0,sol=0,curSol=0,correctFirst=0,curLength=1,maxLength=0; scanf("%d",&stops);
        for(int i=0; i<stops-1;i++) {
            int val; scanf("%d",&val);
            curSol+=val;
            if(curSol<0) { first=i+1; curSol=0; curLength=0; }
            else{
               if(sol==curSol && curLength>maxLength) { correctFirst=first; last=i; maxLength=curLength;}
               else if(sol<curSol) { correctFirst=first; last=i; sol=curSol; maxLength=curLength; }
            }
            curLength++;
        }
        if(sol==0) printf("Route %d has no nice parts\n",cases);
        else printf("The nicest part of route %d is between stops %d and %d\n",cases,correctFirst+1,last+2);
        cases++;
    }
    return 0;
}

/*
28
6
1
0
0
0
1
6
1
0
0
1
-1
10
4
-5
4
-3
4
4
-4
4
-5
10
4
-5
4
-3
4
4
-4
4
5
6
-1
1
-1
1
-1
6
1
-1
1
-1
1
11
1
-1
1
-1
1
-1
1
-1
1
-1
12
1
-1
1
-1
1
-1
1
-1
1
-1
1
7
1
-1
1
-100
1
-1
6
-7
9
15
-16
100
6
-1
-1
-1
-1
6
8
-1
-1
-1
-1
6
-1
7
8
-1
-1
-1
-1
6
-1
7
9
100
-50
-60
-70
-6
-6
-5
-4
6
-4
-3
-2
100
200
4
1
2
3
4
-1000
100
1
2
13
5
1
2
-3
4
3
-19
19
8
1
4
1
3
5
-7
100
4
1
3
5
3
-1 6
10
4 -5 4 1 -10 4 -5 4 1
4
-2 -3 -4
3
-1 6
11
4 -5 4 1 -10 4 -5 2 2 1
4
-2 -3 -4


The nicest part of route 1 is between stops 1 and 6
The nicest part of route 2 is between stops 1 and 5
The nicest part of route 3 is between stops 3 and 9
The nicest part of route 4 is between stops 3 and 10
The nicest part of route 5 is between stops 2 and 5
The nicest part of route 6 is between stops 1 and 6
The nicest part of route 7 is between stops 1 and 10
The nicest part of route 8 is between stops 1 and 12
The nicest part of route 9 is between stops 1 and 4
The nicest part of route 10 is between stops 2 and 6
The nicest part of route 11 is between stops 5 and 6
The nicest part of route 12 is between stops 5 and 8
The nicest part of route 13 is between stops 5 and 8
The nicest part of route 14 is between stops 1 and 2
The nicest part of route 15 is between stops 4 and 6
The nicest part of route 16 is between stops 1 and 4
The nicest part of route 17 is between stops 2 and 4
The nicest part of route 18 is between stops 1 and 2
The nicest part of route 19 is between stops 1 and 5
The nicest part of route 20 is between stops 2 and 3
The nicest part of route 21 is between stops 1 and 8
The nicest part of route 22 is between stops 1 and 4
The nicest part of route 23 is between stops 2 and 3
The nicest part of route 24 is between stops 3 and 5
Route 25 has no nice parts
The nicest part of route 26 is between stops 2 and 3
The nicest part of route 27 is between stops 8 and 11
Route 28 has no nice parts

*/
