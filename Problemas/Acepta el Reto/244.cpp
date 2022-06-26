#include <bits/stdc++.h>
using namespace std;

inline int getchar_unlocked() { return getchar(); }
inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}


int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)==2 && (n!=0||m!=0))
   {
        map<int,int> arrX,arrY;
        int arrAuxX[m],arrAuxY[m];
        for(int i=0; i<m;i++) {int x,y; fastInput(x); fastInput(y); arrX[x]++; arrY[y]++; arrAuxX[i]=x; arrAuxY[i]=y;}
        bool flag=true;
        for(auto m:arrX) //check row
            if(m.second!=1) { flag=false; break; }
        if(flag)
        {
            for(auto m:arrY) //check column
                if(m.second!=1) { flag=false; break; }
        }
        if(flag) //check diagonal
        {
            for(int i=0; i<m && flag;i++)
                for(int j=i+1; j<m && flag;j++)
                {
                   int val = arrAuxX[i]-arrAuxX[j];
                   int val1 = arrAuxY[i]-arrAuxY[j];
                   if(val==val1 ||abs(val)==val1 || val==abs(val1)) flag=false;
                }
        }
        if(!flag) printf("SI\n");
        else printf("NO\n");
   }
   return 0;
}
