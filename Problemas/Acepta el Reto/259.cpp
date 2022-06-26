#include <iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        if(n==1) printf("10\n");
        else{
            printf("9");
            if(n%2==0) for(int i=1; i<n/2;i++) printf("0");
            else for(int i=0; i<n/2;i++) printf("0");
            printf("\n");
        }
    }
    return 0;
}
