#include<iostream>
using namespace std;
 
int main(){
    int num;
    while(scanf("%d",&num)==1){
          string res = "";
          int cnt=0;
          for(int i=num+1;i<=2*num;i++){
            double x=((double)num*(double)i)/((double)i-(double)num);
            if(x==(int)x){
                 res+="1/"+to_string(num)+" = 1/"+to_string((int)x)+" + 1/" + to_string(i) + '\n';
                 cnt++;
            }
          }
        printf("%d\n",cnt);
        cout<<res;
    }
    return 0;
}
