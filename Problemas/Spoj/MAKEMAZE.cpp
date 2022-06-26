#include<bits/stdc++.h>
using namespace std ;
int m1[]={1,0,-1,0};
int m2[]={0,1,0,-1};
bool visited[21][21] ;
int r , c , i , j , x , y ,t,total ;
char s[21][21] ;
 
void bfs()
{
    queue < pair< int , int > > q ;
    pair< int , int > p ;
    for( i = 0 ; i < r ; i++ )
    {
        for( j = 0 ; j < c ; j++ )
        {
            if( s[i][j] == '.' && (i==0 || (i+1) == r || j==0 || (j+1)==c ))
            {
                total++;
                if(total==1)
                {
                visited[i][j] = true;
                q.push( make_pair( i , j ) ) ;
                }
            }
        }
    }
    if(total==2)
    while( !q.empty( ) )
    {
        p = q.front( ) ;
        q.pop( ) ;
        for( i = 0 ; i < 4 ; i++ )
        {
            x = m1[i] + p.first ;
            y = m2[i] + p.second ;
            if( x >= 0 && x < r && y >= 0 && y < c && ( s[x][y] == '.' ) )
            {
                if( !visited[x][y] )
                {
                    visited[x][y] = true ;
                    if((x+1) ==r || (y+1) == c || x==0 || y==0)
                    {
                        total--;
                    break;
                    }
                    q.push( make_pair( x , y ) ) ;
                }
            }
        }
    }
    else
        total=5;
}
int main( )
{
    cin >> t;
    while(t--)
    {
        total=0;
        cin>>r>>c;
        memset( visited , false , sizeof( visited ) ) ;
        for( i = 0 ; i < r ; i++ )
            scanf("%s",s[i]) ;
 
        bfs();
 
        if(total==1)
        cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;
    }
    return 0 ;
} 
