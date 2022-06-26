#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin>>N && N!=0){
        if(N<=101) printf("f91(%d) = 91\n",N);
        else printf("f91(%d) = %d\n",N,N-10);
    }
    return 0;
}
