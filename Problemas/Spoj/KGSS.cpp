#include <bits/stdc++.h>
using namespace std;

struct sum {
   long long int n;
   long long int f;
};

void buildTree(sum *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e) return;
    //reached leaf node
    if(s==e)
    {
        tree[index]=((sum){a[s],1});
        return ;
    }
    //now build the segment tree in bottom up manner
    int m = (s+e)/2;
    buildTree(tree,a,2*index,s,m);
    buildTree(tree,a,2*index+1,m+1,e);
    sum left = tree[2*index]; sum right = tree[2*index+1];
    tree[index].f= max(left.msum,max(right.msum,left.m+right.m));
    tree[index].n= max(left.n,right.n);
    return;
}

//function to query the segment tree for RSQ
sum query(sum *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe)
        return {0,0};
    //complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    sum left = query(tree,2*index,s,m,qs,qe);
    sum right = query(tree,2*index+1,m+1,e,qs,qe);
    return ( ( sum ) { max( left.n, max( right.msum, left.m + right.m ) ), max( left.f, right.f) } );
}

int main()
{
    freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/out.txt","w",stdout);
    int n,c;
    while(scanf("%d%d",&n,&c)==1)
    {
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        sum*tree = new sum[4*n+1];                                    //array to store the segment tree
        int index = 1;						      //index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);				      //now tree has been built
        for(int i=0; i<c;i++)
        {
        int j,k; scanf("%d %d",&j,&k);
        printf("%lld\n",query(tree,index,s,e,j-1,k-1).n);
        }
    }
    return 0;
}
