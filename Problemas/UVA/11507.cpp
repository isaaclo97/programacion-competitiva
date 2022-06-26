#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases;
    while(scanf("%d", &cases)&& cases!=0) {
        int dir = 0;
        string aux;
        //+x(0), -x(1), +y(2), -y(3), +z(4), -z(5)
        for(int i=1; i<cases; i++)
        {
            cin>>aux;
            if(aux=="No")
                continue;
            if(aux=="+z") {
                if(dir == 0)        dir = 4;//+x->+z
                else if(dir == 1)   dir = 5;//-x->-z
                else if(dir == 4)   dir = 1;//+z->-x
                else if(dir == 5)   dir = 0;//-z->+x
            }
            if(aux=="-z") {
                if(dir == 0)        dir = 5;//+x->-z
                else if(dir == 1)   dir = 4;//-x->+z
                else if(dir == 4)   dir = 0;//+z->+x
                else if(dir == 5)   dir = 1;//-z->-x
            }
            if(aux== "+y") {
                if(dir == 0)        dir = 2;//+x->+y
                else if(dir == 1)   dir = 3;//-x->-y
                else if(dir == 2)   dir = 1;//+y->-x
                else if(dir == 3)   dir = 0;//-y->+x
            }
            if(aux=="-y") {
                if(dir == 0)        dir = 3;//+x->-y
                else if(dir == 1)   dir = 2;//-x->+y
                else if(dir == 2)   dir = 0;//+y->+x
                else if(dir == 3)   dir = 1;//-y->-x
            }
        }
        if(dir == 0)   cout<<"+x\n";
        if(dir == 1)   cout<<"-x\n";
        if(dir == 2)   cout<<"+y\n";
        if(dir == 3)   cout<<"-y\n";
        if(dir == 4)   cout<<"+z\n";
        if(dir == 5)   cout<<"-z\n";
    }
    return 0;
}
