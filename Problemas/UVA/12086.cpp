#include <bits/stdc++.h>
using namespace std;

void buildTree(int *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e)
        return;
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
    tree[index]= tree[2*index]+tree[2*index+1];
    return;
}

//function to query the segment tree for RSQ
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe)
        return 0;
    //complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    int left_ans = query(tree,2*index,s,m,qs,qe);
    int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
    return left_ans+right_ans;
}

//function to update a value at position to "pos"
void updateNode(int *tree,int index,int s,int e,int pos,int val)
{
    if(pos<s || pos>e)
        return ;
    if(s==e)
    {
        tree[index] = val;
        return ;
    }
    int m = (s+e)/2;
    updateNode(tree,2*index,s,m,pos,val);
    updateNode(tree,2*index+1,m+1,e,pos,val);
    tree[index] = tree[2*index]+tree[2*index+1];
    return;
}

int main()
{
    int n,ncase=1,flag=1;
    while(scanf("%d",&n)==1 && n!=0)
    {
        if(flag==0)printf("\n");
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        int *tree = new int[4*n+1];                                    //array to store the segment tree
        int index = 1;													//index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);									//now tree has been built
        string n;
        printf("Case %d:\n",ncase++);
        while(cin>>n && n!="END")
        {
        int j,k; scanf("%d %d",&j,&k);
        if(n=="S") updateNode(tree,index,s,e,j-1,k);
        else printf("%d\n",query(tree,index,s,e,j-1,k-1));
        }
        flag=0;
    }
    return 0;
}
