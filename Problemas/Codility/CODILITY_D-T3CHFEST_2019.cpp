#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A)
{
    bool possibleTrip[31]; memset(possibleTrip,false,sizeof(possibleTrip));
    for (auto dayWithTrip : A)  possibleTrip[dayWithTrip] = true;
    int minCostPerDay[31];
    minCostPerDay[0] = 0;
    for (int d = 1; d <= 30; d++) {
        if (!possibleTrip[d]) {
            minCostPerDay[d] = minCostPerDay[d-1];
            continue;
        }
        int minCost = minCostPerDay[d-1] + 2;                    // Possibility #1: one-day pass on day d
        minCost = min(minCost, minCostPerDay[max(0, d-7)] + 7);  // Possibility #2: seven-day pass ending on or after day d
        minCost = min(minCost, 25);                              // Possibility #3: 30-day pass for the whole period
        minCostPerDay[d] = minCost;
    }
    return minCostPerDay[30];
}

int main()
{
  vector<int> A; //Caso base
  int res = solution(A);
  printf("%d\n",res);
  A = {1, 2, 4, 5,7, 29,30}; //Caso de prueba
  res = solution(A);
  printf("%d\n",res);
  A = {1,2,3,4,5,6,8}; //Caso random
  res = solution(A);
  printf("%d\n",res);
  A = {1,2,3,4,5,6,7}; //Caso random
  res = solution(A);
  printf("%d\n",res);
  A = {1,2,3,4,5,6}; //Caso random
  res = solution(A);
  printf("%d\n",res);
  A = {1,2,3,4,5,6,7,9}; //Caso random
  res = solution(A);
  printf("%d\n",res);
  for(int i=1; i<30;i++)
  {
      A = {i};
      int res = solution(A);
      printf("%d\n",res);
      printf("Valores: %d\n",i);
      for(int i1=i+1; i1<30;i1++)
      {
          A = {i,i1};
          int res = solution(A);
          printf("%d\n",res);
          printf("Valores: %d, %d\n",i,i1);
          for(int i2=i1+1; i2<30;i2++)
          {
              A = {i,i1,i2};
              int res = solution(A);
              printf("%d\n",res);
              printf("Valores: %d, %d, %d\n",i,i1,i2);

              for(int i3=i2+1; i3<30;i3++)
              {
                  A = {i,i1,i2,i3};
                  int res = solution(A);
                  printf("%d\n",res);
                  printf("Valores:  %d, %d, %d, %d\n",i,i1,i2,i3);
              }
          }
      }
  }
  return 0;
}
