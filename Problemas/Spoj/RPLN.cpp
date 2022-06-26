#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
 
void buildTree(int *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e) return;
    //reached leaf node
    if(s==e)
    {
        tree[index]=a[s];
        return ;
    }
    //now build the segment tree in bottom up manner
    int m = (s+e)/2;
    buildTree(tree,a,2*index,s,m);
    buildTree(tree,a,2*index+1,m+1,e);
    tree[index]= min(tree[2*index],tree[2*index+1]);
    return;
}
 
//function to query the segment tree for RMQ
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe)
        return INF;
    //complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    int left_ans = query(tree,2*index,s,m,qs,qe);
    int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
    return min(left_ans,right_ans);
}
 
int main()
{
    int n,c,cases,ca=1;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&c);
        int a[n];
        for(int i=0; i<n;i++) scanf("%d",&a[i]);
        int *tree = new int[4*n+1];                                    //array to store the segment tree
        int index = 1;												  //index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);								  //now tree has been built
        printf("Scenario #%d:\n",ca++);
        for(int i=0; i<c;i++)
        {
         int k,j; scanf("%d%d",&k,&j);
         printf("%d\n",query(tree,index,s,e,k-1,j-1));
        }
    }
    return 0;
} 
