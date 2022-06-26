#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    while(scanf("%d%d",&i,&j)==2)
    {
        int max_cycle_length = 0,cycle_length;
        cout<<i<<" "<<j<<" ";
        if ( i > j ) swap (i, j);
        while ( i <= j ) {
            int n = i;
            cycle_length = 1;
            while ( n != 1 ) {
                if ( n % 2 == 1 ) n = 3 * n + 1;
                else n /= 2;
                cycle_length++;
            }
            if ( cycle_length > max_cycle_length )
                max_cycle_length = cycle_length;
            i++;
        }
        printf ("%d\n",max_cycle_length);
    }
    return 0;
 }
