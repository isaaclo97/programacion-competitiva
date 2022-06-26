#include <bits/stdc++.h>

using namespace std;

int main() {
   int A,B,C;
    while(scanf("%d%d%d",&A,&B,&C)==3)
    {
        int res = 0;
        if(A>=B && A>=C)
        {
          if(!(A<(B+C))) res=A-B-C+1;
        }
        if(B>=A && B>=C)
        {
          if(!(B<(A+C))) res=B-A-C+1;
        }
        if(C>=B && C>=A)
        {
          if(!(C<(B+A))) res=C-B-A+1;
        }
        cout<<res<<'\n';
    }
    return 0;
}
