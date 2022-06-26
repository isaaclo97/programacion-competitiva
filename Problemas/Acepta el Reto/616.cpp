
#include <bits/stdc++.h>
using namespace std;

int main(){
    int moves;
    while(scanf("%d",&moves) && moves!=0){
        bool turno = true;
        int l=0,r=0;
        string value;
        for(int i=0; i<moves;i++) {
            cin>>value;
            if(value=="PONG!") { //punto
                if(turno) l++;
                else r++;
            }
            else if(value=="PIC") //cambio
                turno = !turno;
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}

/*
1 PONG!
0
*/
