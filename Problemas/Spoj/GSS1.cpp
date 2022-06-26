#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F

struct node {
   long long int m;
   long long int ml;
   long long int mr;
   long long int s;
};
node join(node left,node right)
{
    /*
    Maximum sum of a subarray, starting at the leftmost index of this range
    Maximum sum of a subarray, ending at the rightmost index of this range
    Maximum sum of any subarray in this range
    Sum of all elements in this range
    */
    node res;
    res.s = left.s+right.s;
    res.ml = max(left.ml,left.s+right.ml);
    res.mr = max(right.mr,right.s+left.mr);
    res.m = max(res.ml, max(res.mr, max(left.m, max(right.m, left.mr + right.ml))));

    return res;
}
void buildTree(node *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e) return;
    //reached leaf node
    if(s==e)
    {
        tree[index].m=tree[index].mr=tree[index].ml=tree[index].s=a[s];
        return ;
    }
    //now build the segment tree in bottom up manner
    int m = (s+e)/2;
    buildTree(tree,a,2*index,s,m);
    buildTree(tree,a,2*index+1,m+1,e);
    node left = tree[2*index]; node right = tree[2*index+1];
    tree[index]=join(left,right);
    return;
}

//function to query the segment tree for RSQ
node query(node *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe) return node{-INF,-INF,-INF,-INF};
    //complete overlap
    if(s>=qs && e<=qe) return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    node left = query(tree,2*index,s,m,qs,qe);
    node right = query(tree,2*index+1,m+1,e,qs,qe);
    return join(left,right);
}
int main()
{
    int n,c;
    while(scanf("%d",&n)==1)
    {
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        node*tree = new node[4*n+1];                                    //array to store the segment tree
        int index = 1;												  //index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);								  //now tree has been built
        scanf("%d",&c);
        for(int i=0; i<c;i++)
        {
        int j,k; scanf("%d %d",&j,&k);
        printf("%lld\n",query(tree,index,s,e,j-1,k-1).m);
        }
    }
    return 0;
}
