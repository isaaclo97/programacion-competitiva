#include <bits/stdc++.h>
using namespace std;
int row, col;
char map1[51][51];
int visited[51][51];
int result;
int dx[8] = {1, 1, 1, 0, 0, -1, -1,-1};
int dy[8] = {1,-1, 0, 1, -1, 1, -1, 0};
 
void DFS(int x, int y, int count)
{
    int i=0;
    if(count>result)
        result = count;
    visited[x][y] = 1;
    for(i=0; i<8; i++)
    {
        int tempx = x + dx[i];
        int tempy = y + dy[i];
        if(tempx>=0&&tempx<row&&tempy>=0&&tempy<col&&map1[tempx][tempy]==(char)map1[x][y]+1&&!visited[tempx][tempy])
        {
            DFS(tempx, tempy, count+1);
        }
    }
}
int main()
{
    int i, j, test=0;
    while(++test)
    {
        result = 0;
        cin>>row>>col;
        if(row==0&&col==0)break;
        for(i=0; i<row; i++)
            scanf("%s", &map1[i]);
        for(i=0; i<row; i++)
            for(j=0; j<col; j++)
            {
                if(map1[i][j] == 'A')DFS(i,j,1);
            }
        printf("Case %d: %d\n", test, result);
        for(i=0; i<row; i++)
            for(j=0; j<col; j++)visited[i][j] = 0;
    }
    return 0;
} 
