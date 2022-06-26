
#include <bits/stdc++.h>
using namespace std;

int corte[505];
int memo[505][505];
int L,N;

int dp(int i_index, int j_index, int left, int right){
    if(i_index<0 || j_index>=N || i_index>j_index) return 0;
    if(i_index == j_index) return right-left;
    int &best = memo[i_index][j_index];
    if(best!=-1) return best;
    int minCost = 0x3f3f3f3f;
    for(int i=i_index;i<=j_index;i++){
        int firstCut = dp(i_index,i-1,left,corte[i])+dp(i+1,j_index,corte[i],right);
        minCost = min(firstCut,minCost);
    }
    return best = minCost + (right-left);
}

int main(){
  //while(scanf("%d %d",&L,&N)==2 && (L!=0 || N!=0)){
  while(scanf("%d",&L)==1 && L!=0){ scanf("%d",&N);
      for(int i=0; i<N;i++) scanf("%d",&corte[i]);
      for(int i=0; i<N;i++)
          for(int j=0; j<N;j++) memo[i][j]=-1;
      sort(corte,corte+N);
      //printf("%d\n",dp(0,N-1,0,L)*2);
      printf("The minimum cutting is %d.\n",dp(0,N-1,0,L));
  }
  return 0;
}
