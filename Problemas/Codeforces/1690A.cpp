
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int num; scanf("%d",&num);
        int h1 = num/3-1;
        int h2 = num/3;
        int h3 = num/3-2;
        int remaining = num-h1-h2-h3;
        for(int i=0; i<remaining;i++){
            if(i%3==0) h2++;
            if(i%3==1) h1++;
            if(i%3==2) h3++;
        }
        if((h1+h2+h3)!=num) cout<<"ERROR\n";
        printf("%d %d %d\n",h1,h2,h3);
    }
    return 0;
}
