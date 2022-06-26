#include <bits/stdc++.h>
using namespace std;
 
int main() {
     queue<int> Q;
     vector<int> visited(1000000);
     int d,u,s,g,f;
     cin>>f>>s>>g>>u>>d;
     if(s==g)
          printf("0\n");
     else
     {
          visited[s]=1;
          Q.push(s);
          while(!Q.empty())
          {
               
               int k=Q.front();
               Q.pop();
               
               if((k+u)<=f && visited[k+u]==0)
               {
                    visited[k+u]=visited[k]+1;
                    Q.push(k+u);
               }
               if((k-d)>=1 && visited[k-d]==0)
               {
                    visited[k-d]=visited[k]+1;
                    Q.push(k-d);
               }           
          }    
          if(visited[g]!=0)
               printf("%d\n",visited[g]-1);
          else
               printf("use the stairs\n");
     }
     return 0;
}
